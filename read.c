#include "sshell.h"

/**
 * readInput - collects user input
 * @input: the user input
 * @size: the sizeof(user input)
 */
void readInput(char *input, size_t size)
{
	if (getline(&input, &size, stdin) == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	if (input[strlen(input) - 1] == '\n')
		input[strlen(input) - 1] = '\0';
}
