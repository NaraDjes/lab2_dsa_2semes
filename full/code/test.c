// crt_clock.c
// This sample uses clock() to 'sleep' for three
// seconds, then determines how long it takes
// to execute an empty loop 600000000 times.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Pauses for a specified number of clock cycles.
void do_sleep(clock_t wait)
{
    clock_t goal;
    goal = wait + clock();
    while (goal > clock())
        ;
}

const long num_loops = 600000000L;

int main(void)
{
    long i = num_loops;
    clock_t start, finish;
    double duration;

    // Delay for a specified time.
    printf("Delay for three seconds\n");
    do_sleep((clock_t)3 * CLOCKS_PER_SEC);
    printf("Done!\n");

    // Measure the duration of an event.
    start = clock();
    while (i--)
        ;
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time to do %ld empty loops is ", num_loops);
    printf("%2.3f seconds\n", duration);
}