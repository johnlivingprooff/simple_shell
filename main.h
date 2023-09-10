#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* prototypes */
void split(char *input, char **args);
void _process(char *path, char **args);
char *_strtok(char *str, const char *delim);

#endif /* MAIN_H */
