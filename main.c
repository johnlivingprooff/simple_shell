#include "sshell.h"

/**
 * main - Entry point
 * @ac: counter
 * @av: arg vector
 * Return: 0 - Success
 */
int main(int ac __attribute__((unused)), char **av)
{
	char input[BUFFER];
	int interactive = isatty(STDIN_FILENO);
	int estat;

	while (1)
	{
		if (interactive)
			printf("($) "); /* only prints in interactive mode */

		/* collects user input */
		if (!readInput(input, sizeof(input)))
			break; /* exit loop on EOF */

		if (strcmp(input, "exit") == 0)
			exit(EXIT_SUCCESS);

		/* executes user command */
		estat = executeInput(input, av);
	}

	return (estat);
}
