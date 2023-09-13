#include "sshell.h"

/**
 * envi - the environment process
 * @envp: the array of env vars
 */
void envi(char **envp)
{
	int count = 0;
	char line[BUFFER];
	FILE *envFile = fopen("/etc/environment", "r");

	if (envFile == NULL)
	{
		perror("Error accessing /etc/environment");
		return;
	}

	while (fgets(line, BUFFER, envFile))
	{
		/* remove new line, and add \0 */
		line[strcspn(line, "\n")] = '\0';
		/* populate the envp array */
		envp[count++] = line;
	}
	envp[count] = NULL;
	fclose(envFile);
}
