//Steven Kyritsis
//Problem 4
#include<stdio.h>

int main(){

    const int SIZE = 128;
    int count = 0;
    char entry[SIZE], new;

    printf("Please enter a stirng: ");
        scanf("%[^\n]s", entry);

    for(int i = 0; i < SIZE; i++){
        if (entry[i] != '\0'){
            new = entry[i] >> 1 + i;
            if (new == 0)
                count++;
        }
        else
            break;
    }

    printf("%i", count);

    return 0;
}