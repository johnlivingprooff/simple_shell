#include "sshell.h"

/**
 * executeInput - executes the users commands
 * @cmds: the user input
 */
void executeInput(char *cmds)
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
		execve(args[0], args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	} else
		waitpid(_child, &status, 0);
}
