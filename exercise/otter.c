#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *input[] = {"ls","-l","/tmp",NULL};

	printf("#yourTerminal-$ ");

	int status; // for the wait call

	pid_t child = fork(); // creates a child process
	if (child == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		execve("/bin/ls", input, NULL);
		perror("execve failed"); // if execve fails
		exit(EXIT_FAILURE);
	} else
		wait(&status);



	return (0);
}
