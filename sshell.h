#ifndef SSHELL_H
#define SSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 80

void readInput(char *input, size_t size);
void executeInput(char *cmds);
void envi(char **envp);

#endif /*SSHELL_H*/
