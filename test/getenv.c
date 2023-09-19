#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * _getenv - collects env var
 * @name: the env VAR
 * Return: env value or NULL if failed
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *env_var, *is_same, *tk_one, *tk_two;
	char *vari = strdup(name);

	while (environ[i] != NULL)
	{
		env_var = environ[i];
		is_same = strchr(env_var, '=');

		tk_one = strtok(vari, "=");
		tk_two = strtok(env_var, "=");

		if (is_same != NULL && strcmp(tk_one, tk_two) == 0)
			return (is_same + 1); /* returns the value of ENV */
		i++;
	}

	return (NULL); /* Environment variable not found */
}

/**
 * main - entry
 * @ac: counter
 * @av: vector
 * Return: 0
 */
int main(int ac, char **av)
{
	char *value;

	if (ac != 2)
	{
		printf("Usage: %s environment_variable\n", av[0]);
		exit(1);
	}

	value = _getenv(av[1]);
	if (value != NULL)
		printf("%s\n", value);
	else
		printf("%s is not found\n", av[1]);

	return (0);
}
