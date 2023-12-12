#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        else
        {
            free(line);
            printf("Error while reading the line from stdin");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}

char **split_line(char *line)
{
    int bufsize = 64;
    int i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "allocation error in split_line: tokens\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, " \t\r\n\a\"");
    while (token != NULL)
    {
        if (token[0] == '#')
        {
            break;
        }
        tokens[i] = token;
        i++;
        if (i >= bufsize)
        {
            bufsize += bufsize;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "reallocation error in split_line: tokens");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " \t\r\n\a\"");
    }
    tokens[i] = NULL;
    return (tokens);
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void handle_no_interactive(void)
{
    int endwhile = 0;

    while(endwhile == 0)
    {
        int _arg = 0;
        char *line;
        char *content;
        char *mix;
        char **args;

        line = read_line();
        if(line == NULL)
        {
            endwhile = 1;
            break;
        }
        if(content == NULL)
            content = concat("", strdup(line));
        else
        {
        }
        printf("Full Content:\n");
        printf("%s", content);
        args = split_line(line);
        

        while(*args != NULL)
        {
            printf("Non-Interactive arg n°%d: %s\n", _arg, *args);
            _arg++;
            args += 1;
        }
        
    }
    
}

void handle_interactive(int argc, char **argv)
{
    int arg = 0;

    printf("Interactive arg count: %d\n", argc);
    while(arg < argc)
    {
        printf("Interactive arg n°%d: %s\n", arg, argv[arg]);
        arg++;
    }
}

int main(int argc, char **argv)
{
    handle_interactive(argc, argv);
    handle_no_interactive();
    return (0);
    
}