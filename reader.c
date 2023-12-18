#include "main.h"
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
			printf("\n");
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

/**
 * split_line - Split a line using common
 * separators
 * @line: Line to separate
 * @separators: String used to separate
 * Return: Array of strings containing a word each
*/
char **split_line(char *line, char *separators)
{
	int bufsize = 64;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, separators);
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
				fprintf(stderr, "reallocation error: tokens");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, separators);
	}
	tokens[i] = NULL;
	return (tokens);
}
