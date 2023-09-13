#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 80

void read_input(char *input, size_t size) {
    if (fgets(input, size, stdin) == NULL) {
        perror("Failed to read input");
        exit(EXIT_FAILURE);
    }
}

void execute_command(char *command) {
    char *args[MAX_INPUT_SIZE];
    size_t arg_count = 0;
    pid_t child_pid = fork();

    char *token = strtok(command, " \n");
    while (token != NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " \n");
    }
    args[arg_count] = NULL;
	printf("%s, %s\n", args[0], args[1]);
    if (child_pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        execve(args[0], args, NULL);
        perror("Execution failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(child_pid, &status, 0);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("sh> ");
        read_input(input, sizeof(input));

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        execute_command(input);
    }

    return EXIT_SUCCESS;
}
