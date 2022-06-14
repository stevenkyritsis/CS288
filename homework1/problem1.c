//Steven Kyritsis
//NJIT CS288-032 Professor Weiwei

#include <stdio.h>
#include <time.h>


//Problem 1: CPU Cache Access Delay
int main(){

    clock_t start, end;
    const int SIZE = 20;
    int array[SIZE];
    double access_time;

    //initialize the array
    for(int i=0; i < SIZE; i++){
        array[i] = i+1;
    }

    int count = 0;
    while(count < 1000){ //keeping array in cache
        printf("%d \n",array[(count%SIZE)]); 
        count++;
    }

    return 0;
}