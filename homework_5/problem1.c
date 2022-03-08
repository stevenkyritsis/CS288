//Problem 1

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

const int SIZE = 100;

int main(){

    unsigned int entry[SIZE],
    temp;

    //keeps track of entries
    int count = 0;

    printf("Please enter the amount of integers in your list: ");
    scanf("%d", &count);
    printf("Please enter any integer: ");
    
    for (int o = 0; o < count; o++){
        scanf("%d", &entry[o]);
    }
        
    for (int i = 0; i < count; i++){
        for (int j = i+1; j < count; j++){
            if (entry[i] > entry[j]){
                temp = entry[i];
                entry[i] = entry[j];
                entry[j] = temp;
            }
        }
    }
    for (int l = 0; l < count; l++){
        printf("%u ", entry[l]);
    }

    return 0;
}