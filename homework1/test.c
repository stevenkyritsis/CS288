#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_SIZE (512*1024*1024)

int main()
{
    clock_t start, end;
    double cpu_time;
    int i = 0;
    int k = 0;
    int count = 0;

    /*
     * MAX_SIZE array is too big for stack.This is an unfortunate rough edge of the way the stack works. 
     * It lives in a fixed-size buffer, set by the program executable's configuration according to the 
     * operating system, but its actual size is seldom checked against the available space.
     */

    /*int arr[MAX_SIZE];*/

    int *arr = (int*)malloc(MAX_SIZE * sizeof(int));

    /*cpu clock ticks count start*/

    for(k = 0; k < 3; k++)
    {
        start = clock();
        count = 0;

        for (i = 0; i < MAX_SIZE; i++)
        { 
            arr[i] += 3;
            /*count++;*/
        }

        /*cpu clock ticks count stop*/
        end = clock();

        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("cpu time for loop 1 (k : %4d) %.1f ms.\n",k,(cpu_time*1000));
    }

    printf("\n");
    for (k = 1 ; k <= 1024 ; k <<= 1)
    {
        /*cpu clock ticks count start*/
        start = clock();
        count = 0;

        for (i = 0; i < MAX_SIZE; i += k) 
        {
            /*count++;*/
            arr[i] += 3;
        }

        /*cpu clock ticks count stop*/
        end = clock();

        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("cpu time for loop 2 (k : %4d) %.1f ms.\n",k,(cpu_time*1000));
    }
    printf("\n");

    /* Third loop, performing the same operations as loop 2, 
       but only touching 16KB of memory
     */
    for (k = 1 ; k <= 1024 ; k <<= 1)
    {
        /*cpu clock ticks count start*/
        start = clock();
        count = 0;

        for (i = 0; i < MAX_SIZE; i += k) 
        {
            count++;
            arr[i & 0xfff] += 3;
        }

        /*cpu clock ticks count stop*/
        end = clock();

        cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("cpu time for loop 3 (k : %4d) %.1f ms.\n",k,(cpu_time*1000));
    }

    return 0;
}