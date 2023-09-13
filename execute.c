#include "sshell.h"

/**
 * executeInput - executes the users commands
 * @cmds: the user input
 * @av: arg vector
 */
void executeInput(char *cmds, char **av)
{
	char *args[BUFFER];
	int status;
	size_t count = 0;
	pid_t _child = fork();
	char *token;
	char *envp[BUFFER];

	if (_child == -1)
	{
		perror("process failed");
		exit(EXIT_FAILURE);
	} else if (_child == 0)
	{
		token = strtok(cmds, " \n");
		while (token != NULL)
		{
			args[count++] = token;
			token = strtok(NULL, " \n");
		}
		args[count] = NULL;
		_environ(envp);
		if (strchr(args[0], '/') != NULL)
		{
			execve(args[0], args, envp);
			perror(av[0]);
			exit(EXIT_FAILURE);
		} else
			npath(envp, args);
	} else
		waitpid(_child, &status, 0);
}
