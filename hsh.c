#include "main.h"
/**
 * handle_no_interactive - Handle the
 * non-interactive process of hsh
 * @filePath: Path of the program
 * @envp: Environment variables
*/
void handle_no_interactive(char *filePath, char **envp)
{
	int endwhile = -1;
	int lineNumber = 0;

	while (endwhile == -1)
	{
		char *line;
		char **args;

		line = read_line();
		if (line == NULL)
		{
			endwhile = 1;
			break;
		}
		args = split_line(line, ARG_SEPARATOR);
		lineNumber++;
		endwhile = parse_args(args, filePath, lineNumber, envp);
		if (endwhile >= 0)
			exit(endwhile);
	}
}

/**
 * handle_interactive - Handle the
 * interactive process of hsh
 * @filePath: Path of the program
 * @envp: Environment variables
*/
void handle_interactive(char *filePath, char **envp)
{
	char *line;
	char **args;
	int status = -1;
	int lineNumber = 0;

	do {
		printf("($) ");
		line = read_line();
		args = split_line(line, ARG_SEPARATOR);
		lineNumber++;
		status = parse_args(args, filePath, lineNumber, envp);
		free(line);
		free(args);
		if (status >= 0)
			exit(status);
	} while (status == -1);
}

/**
 * main - HSH main function
 * @argc: Argument count
 * @argv: Argument values
 * @envp: Environment variables
 * Return: Always 0
*/
int main(int argc, char **argv, char **envp)
{
	if (argc < 1)
		return (1);
	if (isatty(STDIN_FILENO) == 1)
		handle_interactive(argv[0], envp);
	else
		handle_no_interactive(argv[0], envp);
	return (0);
}
