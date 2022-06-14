//Steven Kyritsis
//NJIT CS288-032 Professor Weiwei

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Problem 1: CPU Cache Access Delay
int main(){

    clock_t start, end;
    const int SIZE = 20;
    int *array=(int*)malloc(SIZE * sizeof(int));
    double latency_access_time;

    //initialize the array
    for(int i=0; i < SIZE; i++){
        array[i] = i+1;
    }

    for(int j = 0; j < 4; j++){
        start = clock();
        int count = 0;
        while(count < 10000000){ //keeping array in cache
            //printf("%d \n",array[(count%SIZE)]); used for testing purposes
            count++;
        }
        end = clock();

        latency_access_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("The access time for CPU cache for loop %d: %f s\n",j,latency_access_time);
    }
    
    return 0;
}