#include "sshell.h"

/**
 * readInput - collects user input
 * @input: the user input
 * @size: the sizeof(user input)
 */
void readInput(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
		exit(EXIT_FAILURE);
}
