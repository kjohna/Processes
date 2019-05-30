// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp;
    fp = fopen("text.txt", "r+");
    int rc;

    fprintf(fp, "Something Here %d\n", rc);
    rc = fork();
    fprintf(fp, "after fork %d\n", rc);

    if (rc < 0)
    {
        // fork failed
        printf("fork failed :(\n");
    }
    else if (rc == 0)
    {
        // child
        printf("child process\n");
        fprintf(fp, "child writes to file\n");
    }
    else
    {
        // parent
        printf("parent process\n");
        fprintf(fp, "parent writes to file\n");
    }
    fclose(fp);
    return 0;
}
