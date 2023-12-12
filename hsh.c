#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int execute_process(char **args, char *filePath, int lineNumber)
{
	pid_t pid;
	int status;
	char *message = malloc(64 * sizeof(char));

	pid = fork();
	if (pid ==  0)
	{
		if (execvp(args[0], args) == -1)
		{
			sprintf(message, "%s: %d", filePath, lineNumber);
			perror(message);
		}	
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		sprintf(message, "%s: %d", filePath, lineNumber);
		perror(message);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(message);
	return (-1);
}
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
			break;
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

int parse_args(char **args, char *filePath, int lineNumber)
{
	if (args[0] == NULL)
		return (-1);
	return (execute_process(args, filePath, lineNumber));
}

void handle_no_interactive(char *filePath)
{
	int endwhile = -1;
	int lineNumber = 0;

	while(endwhile == -1)
	{
		char *line;
		char **args;

		line = read_line();
		if(line == NULL)
		{
			endwhile = 1;
			break;
		}
		args = split_line(line);
		lineNumber++;
		endwhile = parse_args(args, filePath, lineNumber);
		if(endwhile >= 0)
			exit(endwhile);
	}
	
}

void handle_interactive(char *filePath)
{
	char *line;
	char **args;
	int status = -1;
	int lineNumber = 0;

	do {
		printf("($) ");
		line = read_line();
		args = split_line(line);
		lineNumber++;
		status = parse_args(args, filePath, lineNumber);
		free(line);
		free(args);
		if (status >= 0)
			exit(status);
	} while (status == -1);
}

int main(int argc, char **argv)
{
	if(argc < 1)
		return (1);

	if (isatty(STDIN_FILENO) == 1)
		handle_interactive(argv[0]);
	else 
		handle_no_interactive(argv[0]);
	return (0);
}