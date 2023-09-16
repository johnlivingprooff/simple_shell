#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 80

int readInput(char *input, size_t size);
int executeInput(char *cmds, char **av);
void _environ(char **envp);
void npath(char **envp, char **args, char **av);

#endif /*SSHELL_H*/
