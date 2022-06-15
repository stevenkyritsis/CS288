//Steven Kyritsis
//NJIT CS288-032 Professor Weiwei

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Problem 1: CPU Cache Access Delay
int main(){

    clock_t start, end;
    long SIZE = ((long) 9223372036854775807);
    const int CACHE_BLOCK = 6 * 1000000;
    long *array=(long*)malloc(SIZE * sizeof(long));
    double latency_access_time;

    //initialize the array
    for(long i=0; i < SIZE; i++){
        array[i] = i+1;
    }
    
    //array for cache
    int *arr = (int*)malloc(CACHE_BLOCK * sizeof(int)); //24MB

    //initialize the array
    for(int i=0; i < CACHE_BLOCK; i++){
        arr[i] = i+1;
    }    

    for(int j = 0; j < 100; j++){
        for(int i = 0; i < CACHE_BLOCK; i++){
            arr[i];
        }
    }
    
    for(int j = 0; j < 4; j++){
        start = clock();
        long count = 0;
        while(count < SIZE){ //keeping array in cache
            //printf("%d \n",array[(count%SIZE)]); used for testing purposes
            for(int j = 0; j < 100; j++){
                for(int i = 0; i < CACHE_BLOCK; i++){
                    arr[i];
                }
            }
            array[(count)];
            count++;
        }
        end = clock();

        latency_access_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("The access time for RAM cache for loop %ld: %.20lfs\n",j,(latency_access_time));
    }
    
    return 0;
}