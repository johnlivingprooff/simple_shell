#include "main.h"

/**
 * split - turns user input into tokens
 * @input: the user's input
 * @args: the array for each token
 */
void split(char *input, char **args)
{
	char *token = _strtok(input, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = _strtok(NULL, " ");
	}
	args[i] = NULL;
}
