#include "sshell.h"
/**
 * _child - function for child process
 * @path: path of executable file/command
 * @tok: tokenized user input
 * Return: 0 on success
 */
int _child(char *path, char **tok)
{
	pid_t child_pid;
	int status;
	int exe_state;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == 0)
	{
		exe_state = execve(path, tok, envp);
		if (exe_state == -1)
			return (-1);
	}
	if (child_pid == -1)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);

	return (0);
}

