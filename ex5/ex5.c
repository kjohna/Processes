// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    // Your code here
    // establish pipe
    char buffer[MSGSIZE];
    int p[2];
    if (pipe(p) < 0)
    {
        printf("pipe failed \n");
        exit(1);
    }
    // fork
    int rc = fork();

    if (rc < 0)
    {
        printf("fork failed.\n");
    }
    else if (rc == 0)
    {
        // child
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
    }
    else
    {
        // parent waits for child
        int wc = waitpid(rc, NULL, 0);
        // then reads the message
        for (int i = 0; i < 3; i++)
        {
            read(p[0], buffer, MSGSIZE);
            printf("child said: %s \n", buffer);
        }
    }

    return 0;
}
