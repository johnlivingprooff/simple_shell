#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - Proogram that prints a PPID
 *
 * Return: 0 - success
 */
int main(void)
{
	pid_t c_ppid, c_pid; 
	int i, stop = 50;

	c_ppid = getppid();
	c_pid = getpid();

	i = 0;
	while (i <= stop)
	{
		printf("ParentPID:[%u] ProcessID:[%u]\n", c_ppid, c_pid);
		i++;
	}
	return (0);
}

