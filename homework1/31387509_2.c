//Steven Kyritsis
//NJIT CS288-032 Professor Weiwei

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Problem 2: RAM Access Delay
int main(){

    clock_t start, end;
    const int SIZE = (1024 * 1024);
    int *array=(int*)malloc(SIZE * sizeof(int));
    double latency_access_time;
    int random;

    //initialize the array
    for(int i=0; i < SIZE; i++){
        array[i] = i+1;
    }

    for(int j = 0; j < 4; j++){
        start = clock();
        array[(random%SIZE)];
        end = clock();

        latency_access_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("The access time for RAM for loop %d: %.10fs\n",j,(latency_access_time));
    }
    
    return 0;
}
