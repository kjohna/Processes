// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    int rc = fork();

    if (rc < 0)
    {
        printf("fork failed!\n");
    }
    else if (rc == 0)
    {
        // exec and/or variants here
        // http://man7.org/linux/man-pages/man3/exec.3.html
        // execl()
        // char *pathname = "/bin/ls";
        // char *arg = "-a -l";
        // char *end = NULL;
        // execl(pathname, arg, end);
        // execv()
        char *pathname = "/bin/ls";
        char *args[2];
        args[0] = "-a";
        args[1] = NULL;
        execv(pathname, args);
    }
    else
    {
        printf("parent continues one with other business.\n");
    }
    return 0;
}
