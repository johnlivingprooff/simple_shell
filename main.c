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
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	} else
		waitpid(_child, &status, 0);
}

/**
 * main - Entry point
 *
 * Return: 0 - Success
 */
int main(void)
{
	char input[BUFFER];

	while (1)
	{
		printf("($) ");
		/* collects user input */
		readInput(input, sizeof(input));
		/* executes user command */
		executeInput(input);
	}

	return (0);
}
