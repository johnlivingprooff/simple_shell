#include "sshell.h"

/**
 * readInput - collects user input
 * @input: the user input
 * @size: the sizeof(user input)
 */
void readInput(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		perror("failed to read input");
		exit(EXIT_FAILURE);
	}
}
