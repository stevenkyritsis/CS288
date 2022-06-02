//Steven Kyritsis
//Problem 1

#include <stdio.h>

int main() {

    unsigned int num;
    int start, end;

    printf("Please enter an unsigned integer: ");
        scanf("%u", &num);
    
    printf("Please enter the start bit: ");
        scanf("%d", &start);
    printf("Please enter the end bit: ");
        scanf("%d", &end);
    

    unsigned int shifty_start = num << (31-end);
    unsigned int shifty_end = shifty_start >> (31 - end + start); 
    
    printf("The value is %d", shifty_end);

    return 0;
}