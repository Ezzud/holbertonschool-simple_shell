#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * read_line - Read a line from stdin
 * Return: the line found in stdin
*/
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(line);
            return (NULL);
        }
        else
        {
            free(line);
            printf("Error while reading the line from stdin");
            return (NULL);
        }
    }
    return (line);
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

    printf("Full Content:\n");
    while(endwhile == 0)
    {
        char *line;

        line = read_line();
        if(line == NULL)
        {
            endwhile = 1;
            break;
        }

        printf("%s\n", line);        
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