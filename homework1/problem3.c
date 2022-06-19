//Steven Kyritsis
//NJIT CS288-032 Professor Weiwei

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Problem 1: CPU Cache Access Delay
int main(){

    clock_t start, end;
    FILE file_read*;
    double latency_access_time;

    for(int j = 0; j < 4; j++){
        start = clock();
        int count = 0;
        while(count < 100){ //keeping array in cache
            //printf("%d \n",array[(count%SIZE)]); used for testing purposes
            array[(count%SIZE)];
            count++;
        }
        end = clock();

        latency_access_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("The access time for CPU cache for loop %d: %.10fs\n",j,(latency_access_time/count));
    }
    
    return 0;
}