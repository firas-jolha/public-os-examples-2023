#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pipe_fd[2];  // File descriptors for the pipe
    pid_t child_pid; // Process ID of the child

    // Create a pipe
    pipe(pipe_fd);

    // Fork to create a child process
    child_pid = fork();

    if (child_pid == 0)
    {
        // This code is executed by the child process

        // Close the read end of the pipe (not needed by child)
        close(pipe_fd[0]);

        // Input read from the command line by the child
        char input[100];
        printf("Child: Enter input: ");
        fgets(input, sizeof(input), stdin);

        // Write the input to the pipe
        write(pipe_fd[1], input, sizeof(input));

        // Close the write end of the pipe
        close(pipe_fd[1]);
    }
    else
    {
        // This code is executed by the parent process

        // Close the write end of the pipe (not needed by parent)
        close(pipe_fd[1]);

        // Read data from the pipe and print it to stdout
        char buffer[100];
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Parent received from child: %s", buffer);

        // Close the read end of the pipe
        close(pipe_fd[0]);
    }

    return 0;
}
