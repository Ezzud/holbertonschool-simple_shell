#ifndef _HSH_
#define _HSH_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ARG_SEPARATOR " \t\r\n\a\""
#define ENV_SEPARATOR "="
#define PATH_SEPARATOR ":"

char *read_line(void);
char **split_line(char *line, char *separators);
int execute_process(char **args, char *filePath, int lineNumber, char **envp);
int parse_args(char **args, char *filePath, int lineNumber, char **envp);
char **getPathFolders(char **envp);
char *getCommandToAllPaths(char** folders, char *commandName);
#endif