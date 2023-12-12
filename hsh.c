#include "main.h"
#include <string.h>

/**
 * handle_no_interactive - Handle the
 * non-interactive process of hsh
 * @filePath: Path of the program
*/
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

/**
 * handle_interactive - Handle the
 * interactive process of hsh
 * @filePath: Path of the program
*/
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