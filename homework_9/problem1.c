//Problem 1

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int main(int argc, char *argv[]){

    int input, flag;

    while(flag != EOF){
        printf("Enter an integer: ");
        flag = scanf("%d", &input);
    }

    printf("%d \n", input);

    return 0;
}