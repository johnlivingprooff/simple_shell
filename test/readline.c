#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER 1024

/**
 * main - readline
 *
 * Return: 0
 */
int main(void)
{
	char *input, *user_i __attribute__((unused));
	size_t buffer = BUFFER;
	int c_read;

	input = malloc(BUFFER);
	if (input == NULL)
	{
		free(input);
		return (1);
	}

	printf("$ ");
	c_read = getline(&input, &buffer, stdin);
	if (c_read == -1)
		return (1);

	printf("%s", input);
	free(input);
	return (0);
}
