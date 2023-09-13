#include "sshell.h"

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

		if (strcmp(input, "exit\n") == 0)
			exit(0);
		/* executes user command */
		executeInput(input);
	}

	return (0);
}
