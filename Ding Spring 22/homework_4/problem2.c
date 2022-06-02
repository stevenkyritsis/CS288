//Steven Kyritsis
//Problem 2

#include <stdio.h>

int main(){

    int entry,count, high=0;
    
    printf("Please input a number: ");
        scanf("%d", &entry);

    for(int i = 0; i < 32; i++){
        int move = entry >> 1+i;
        if(move == 1){
            count++;
            if (count > high){
                high = count;
            }
            if (move == 0){
                count = 0;
            }
        }
    }

    printf("%d",high);

    return 0;
}