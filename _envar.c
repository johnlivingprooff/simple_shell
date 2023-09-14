#include "sshell.h"
/**
 * _getenv - gets an environment variable
 * @var: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *var)
{
	char **env_copy;
	char *var, *val, *path;
	int comp;
	unsigned int path_len, env_len, len, i;

	env_len = 0;
	while (env[env_len] != NULL)
		env_len+;
	env_copy = NULL;
	env_copy = copy_env(env_copy, env_len);

	len = _strlen((char *)name);
	i = 0;
	while (env_copy[i] != NULL)
	{
		var = env_copy[i];
		comp = _strncmp((char *)name, var, len);
		if (comp == 1)
		{
			val = strtok(var, "=");
			val = strtok(NULL, "\n ");
			if (val == NULL)
			{
				errors(4);
				exit(EXIT_FAILURE);
			}
			path_len = _strlen(value);
			path = malloc(sizeof(char) * path_len + 1);
			if (path == NULL)
			{
				errors(3);
				return (NULL);
			}
			path = _strcpy(path, value);
			free_dp(env_copy, env_len);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * dup_env - Duplicates environment variable
 * @env_dup: Pointer to duplicate environment variable
 * @env_len: length of environment variable
 * Return: double pointer to duplicate of environment variable
 */
char **dup_env(char **env_copy, unsigned int env_len)
{
	char *var;
	unsigned int var_len;
	unsigned int i;

	env_copy = malloc(sizeof(char **) * (env_len));
	if (env_copy == NULL)
	{
		errors(3);
		return (NULL);
	}

	i = 0;
	while (i < env_len)
	{
		var = env[i];
		var_len = _strlen(var);

		env_copy[i] = malloc(sizeof(char) * var_len + 1);
		if (env_copy[i] == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(env_copy[i], env[i]);
		i++;
	}

	return (env_copy);
}

