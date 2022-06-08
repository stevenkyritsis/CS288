#include <stdio.h>


//Problem 1: CPU Cache Access Delay
int main(){

    const int SIZE = 20;
    int array[SIZE];
    
    for(int i=0; i < SIZE; i++){
        array[i] = i;
    }

    int count = 0;
    while(count < 1000){ //keeping array in cache
        printf("%d \n",array[(count%SIZE)]); 
        count++;
    }

    return 0;
}