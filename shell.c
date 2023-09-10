#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 - success
 */
int main(void)
{
	size_t buffer = 1024;
	char *input = NULL, *args[64], path[128];
	ssize_t err;

	while (1)
	{
		printf("($) ");
		input = (char *)malloc(buffer);
		if (!input)
		{
			perror("Allocation Failure");
			exit(EXIT_FAILURE);
		}

		err = getline(&input, &buffer, stdin);
		if (err == -1)
		{
			perror("getline error");
			free(input);
			exit(EXIT_FAILURE);
		}
		if (input[strlen(input) - 1] == '\n')
			input[strlen(input) - 1] = '\0';
		split(input, args);

		/* here we compare some cmds */
		if (strcmp(args[0], "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		snprintf(path, buffer, "/bin/%s", args[0]);
		_process(path, args);
		free(input);
	}
	return (0);
}
