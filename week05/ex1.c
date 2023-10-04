#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    int pipe_fd[2];
    pipe(pipe_fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        close(pipe_fd[1]); // Close the write end of the pipe in the child process

        char message[256];
        int len;

        // Read the message length from the pipe
        read(pipe_fd[0], &len, sizeof(int));

        // Read the message from the pipe
        read(pipe_fd[0], message, len);

        close(pipe_fd[0]); // Close the read end of the pipe in the child process

        printf("Child Process Received: %s\n", message);
    }
    else
    {
        // Parent process
        close(pipe_fd[0]); // Close the read end of the pipe in the parent process

        char *message = argv[1];
        int len = strlen(message);

        // Send the message length to the child process
        write(pipe_fd[1], &len, sizeof(int));

        // Send the message to the child process
        write(pipe_fd[1], message, len);

        close(pipe_fd[1]); // Close the write end of the pipe in the parent process
    }

    return 0;
}
