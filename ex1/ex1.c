// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    printf("before fork, x = %d\n", x);
    int rc = fork();

    if (rc < 0)
    {
        // fork failed
        printf("fork failed :(\n");
    }
    else if (rc == 0)
    {
        printf("child says x = %d\n", x);
        x = 50;
        printf("child changed x to %d\n", x);
    }
    else
    {
        printf("parent says x = %d\n", x);
        x = 75;
        printf("parent changed x to %d\n", x);
    }
    return 0;
}
