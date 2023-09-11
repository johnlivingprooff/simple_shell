#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 - success
 */
int main(void)
{
	size_t buffer = 1024;
	char *input = NULL, **args[MAX_ARGS], *envp[MAX_LINE_LEN], path[64];

	while (1)
	{
		printf("($) ");
		input = (char *)malloc(buffer);
		if (!input)
		{
			perror("Allocation Failure");
			free(input);
			exit(EXIT_FAILURE);
		}
		if (getline(&input, &buffer, stdin) == -1)
		{
			perror("");
			free(input);
			exit(EXIT_FAILURE);
		}
		if (input[strlen(input) - 1] == '\n')
			input[strlen(input) - 1] = '\0';
		split(input, args);
		/* here we compare some cmds */
		if (strcmp(*args[0], "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		_environ(envp);
		snprintf(path, buffer, "/bin/%s", *args[0]);
		_process(path, *args, envp);
		free(input);
	}
	return (0);
}
