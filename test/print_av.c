#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - prints av
 * @ac: arg count
 * @av: arg vector
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av)
{
	int i;

	i = 0;
	printf("%s\n", av[0]);
	while (i < ac)
	{
		printf("%s\n", av[i]);
		i++;
	}

	return (0);
}
