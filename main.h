#ifndef _HSH_
#define _HSH_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *read_line(void);
char **split_line(char *line);
int execute_process(char **args, char *filePath, int lineNumber);
int parse_args(char **args, char *filePath, int lineNumber);
#endif