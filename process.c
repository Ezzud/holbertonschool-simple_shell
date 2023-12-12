#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_process - Execute a process from args
 * @args: Command line
 * @filePath: name of the script file path
 * @lineNumber: Line number of the script to execute
*/
int execute_process(char **args, char *filePath, int lineNumber)
{
	pid_t pid;
	int status;
	char *message = malloc(64 * sizeof(char));

	pid = fork();
	if (pid ==  0)
	{
		if (execve(args[0], args, NULL) == -1)
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

int parse_args(char **args, char *filePath, int lineNumber)
{
	if (args[0] == NULL)
		return (-1);
	return (execute_process(args, filePath, lineNumber));
}