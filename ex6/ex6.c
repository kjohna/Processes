/*
Write a program that will find the average time it takes for your computer
to make a system call an empty write to stdout. Your program should use the 
`clock_gettime` procedure to time how long a single system call takes. It'll 
do this for one million iterations, and then find the average of all of those 
iterations in nanoseconds.
For some helpful documentation and examples of using time-related system calls,
visit this site: https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
While the linked site does say that `clock_gettime()` does not work on OSX, this 
turns out to only be the case for OSX versions < 10.12. Anything later than that 
and `clock_gettime()` should work just fine. 
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define number_iter 50 //1000000
#define BILLION 1000000000L

int main()
{
    // Your code here
    // a struct for clock_gettime() to populate:
    struct timespec start, end;
    // store difference calc here
    double diff, avg;
    int first = 1;

    for (int i = 0; i < number_iter; i++)
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        // time how long this takes:
        printf("");
        // sleep(1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        diff = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.;

        // printf("start: %lf\n", start.tv_sec + start.tv_nsec / 1000000000.);
        // printf("end: %lf\n", end.tv_sec + end.tv_nsec / 1000000000.);
        // printf("%lf\n", diff);
        // calc simple moving average:
        if (first)
        {
            avg = diff;
            first = 0;
        }
        else
        {
            avg = (diff + (float)i * avg) / ((float)i + 1);
        }
        // if (!(i % 100000))
        // {
        printf("current: %lf ", diff);
        printf("%d, average time taken: %lf s\n", i, avg);
        // }
    }
    printf("FINAL average time taken: %lf s after %d runs.\n", avg, number_iter);
    return 0;
}
