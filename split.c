#include "main.h"

/**
 * split - turns user input into tokens
 * @input: the user's input
 * @args: the array for each token
 */
void split(char *input, char ***args)
{
	char *token;
	int i = 0, count = 0;

	if (input == NULL)
		exit(EXIT_FAILURE);

	token = strtok(input, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}

	*args = (char **)malloc(sizeof(char *) * (count + 1));
	if (*args == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " ");
	while (token != NULL)
	{
		(*args)[i] = strdup(token);
		if ((*args)[i] == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
