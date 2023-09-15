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

	while (1)
	{
		printf("($) ");
		/* collects user input */
		readInput(input, sizeof(input));

		if (strcmp(input, "exit") == 0)
			exit(0);
		/* executes user command */
		executeInput(input, av);
	}

	return (0);
}
