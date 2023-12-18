#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * commandExists - Check if a command exists
 * @args: Script arguments
 * @filePath: name of the script file path
 * @lineNumber: Line number of the script to execute
 * @envp: Environment variables
 * Return: Path of the command, Or NULL
 * if not exists
*/
char *commandExists(char **args, char *filePath, int lineNumber, char **envp)
{
	char *commandPath;
	char **pathFolders = getPathFolders(envp);

	if (pathExists(args[0]) < 1)
	{
		commandPath = getCommandToAllPaths(pathFolders, args[0]);

		free(pathFolders);
		if (commandPath == NULL)
		{
			printf("%s: %d: No such file or directory\n", filePath, lineNumber);
			free(commandPath);
			return (NULL);
		}
		else
			return (commandPath);
	}
	free(pathFolders);
	return (strdup(args[0]));
}
/**
 * execute_process - Execute a process from args
 * @args: Command line
 * @filePath: name of the script file path
 * @lineNumber: Line number of the script to execute
 * @envp: Environment Variable
 * Return: Result status of the process
*/
int execute_process(char **args, char *filePath, int lineNumber, char **envp)
{
	pid_t pid;
	int status;
	char *message = malloc(64 * sizeof(char));
	char *commandPath = commandExists(args, filePath, lineNumber, envp);

	if (commandPath == NULL)
	{
		free(message);
		free(commandPath);
		return (-1);
	}

	pid = fork();
	if (pid ==  0)
	{
		if (execve(commandPath, args, envp) == -1)
		{
			sprintf(message, "%s: %d", filePath, lineNumber);
			perror(message);
		}
		free(message);
		free(commandPath);
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
	free(commandPath);
	free(message);
	return (-1);
}

/**
 * parse_args - Parse argument to execute
 * a process
 * @args: Arguments
 * @filePath: Path of the executable
 * @lineNumber: Line number of the script
 * @envp: Environment variables
 * Return: Status of the process execution
*/
int parse_args(char **args, char *filePath, int lineNumber, char **envp)
{
	if (args[0] == NULL)
		return (-1);
	return (execute_process(args, filePath, lineNumber, envp));
}
