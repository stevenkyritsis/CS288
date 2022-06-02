//Steven Kyritsis
//Problem 3

#include<stdio.h>


int main(){

    const int SIZE = 128;

    char entry[SIZE], new;

    printf("Please enter a stirng: ");
        scanf("%[^\n]s", entry);

    for(int i = 0; i < SIZE; i++){
        if (entry[i] != '\0'){
            new = entry[i] >> 31;
            entry[i] = new;
        }
        else
            break;
    }

    for(int i = 0; i < SIZE; i++){
        printf("%s", &entry[i]);
    }

    return 0;
}