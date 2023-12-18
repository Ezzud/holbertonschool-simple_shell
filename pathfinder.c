#include "main.h"
#include <dirent.h>
#include <sys/stat.h>

/**
 * getArrayLength - get the length of an
 * array of string
 * @arr: Array of string
 * Return: Length of the array
*/
int getArrayLength(char **arr)
{
	int i = 0;

	while (arr[i])
		i++;
	return (i);
}

/**
 * pathExists - Check if a path exists
 * @path: Path to check
 * Return: 1 if found, 0 if not found
*/
int pathExists(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

/**
 * getPathFolders - Filter all folders
 * from PATH env variable
 * @envp: Environment variables
 * Return: Array of string containing
 * all the paths
*/
char **getPathFolders(char **envp)
{
	int i = 0;

	while (envp[i])
	{
		if (envp[i] != NULL)
		{
			char *lin = strdup(envp[i]);
			char **args = split_line(lin, ENV_SEPARATOR);
			int argsLength = getArrayLength(args);

			if (argsLength > 1 && strcmp(args[0], "PATH") == 0)
			{
				char **paths = split_line(args[1], PATH_SEPARATOR);
				int pathLength = getArrayLength(paths);

				free(args);
				if (pathLength > 0)
					return (paths);
				return (NULL);
			}
		}
		i++;
	}
	return (NULL);
}

/**
 * getCommandPath - Check if a command exists
 * recursively starting from a path
 * @basePath: Root of the search
 * @commandName: Name of the command
 * Return: Command path, or NULL if not found
*/
char *getCommandPath(char *basePath, char *commandName)
{
	char *path = malloc(sizeof(char) * 1024);
	struct dirent *dp;
	DIR *dir = opendir(basePath);

	if (!dir)
	{
		free(path);
		return (NULL);
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (strcmp(dp->d_name, ".") != 0 &&
			strcmp(dp->d_name, "..") != 0 &&
			strcmp(dp->d_name, "X11") != 0)
		{
			struct stat sb;

			strcpy(path, basePath);
			strcat(path, "/");
			strcat(path, dp->d_name);
			if (stat(path, &sb) == 0 && sb.st_mode & S_IXUSR)
			{
				if (strcmp(commandName, dp->d_name) == 0)
				{
					closedir(dir);
					return (path);
				}
			}
			getCommandPath(path, commandName);
		}
	}
	closedir(dir);
	free(path);
	return (NULL);
}

/**
 * getCommandToAllPaths - Get the command
 * path searching on a list of folders
 * @folders: Folders to search
 * @commandName: name of the command
 * Return: Command Name, or NULL if not found
*/
char *getCommandToAllPaths(char **folders, char *commandName)
{
	int i = 0;

	while (folders[i])
	{
		char *path = getCommandPath(folders[i], commandName);

		if (path != NULL)
			return (path);
		i++;
	}
	return (NULL);
}
