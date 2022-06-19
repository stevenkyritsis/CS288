//Steven Kyritsis
//NJIT CS288-032 Professor Weiwei

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Problem 1: CPU Cache Access Delay
int main(){

    clock_t start, end;
    const int SIZE = (2 * 1024 * 1024);
    const int CACHE_SIZE = 47104;
    int *array=(int*)malloc(SIZE * sizeof(int));
    double latency_access_time;

    //initialize the array
    for(int i=0; i < SIZE; i++){
        array[i] = i+1;
    }

    int *arr=(int*)malloc(CACHE_SIZE * sizeof(int));
    for (int i=0; i < CACHE_SIZE; i++){
        arr[(i)];
    }

    for(int j = 0; j < 4; j++){
        start = clock();
        int count = 0;
        while(count < SIZE){
            array[(count)];
            count++;
        }
        end = clock();

        latency_access_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("The access time for CPU cache for loop %d: %.10fs\n",j,(latency_access_time));
    }
    
    return 0;
}