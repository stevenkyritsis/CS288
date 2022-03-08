//Problem 2

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

const int SIZE = 100;

int main(){

    float entry[SIZE],
    temp;

    //keeps track of entries
    int count = 0;

    printf("Please enter the amount of real numbers in your list: ");
    scanf("%d", &count);

    printf("Please enter any real number: ");
    for (int o = 0; o < count; o++){
        scanf("%f", &entry[o]);
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
        printf("%f ", entry[l]);
    }

    return 0;
}