//Problem 3

#include <stdio.h>
#include <string.h>

void bubble_sort(char *arr[], int size);

int main(int argc, char **argv, char *envp[]){
        int i = 0;

        printf("Before sorting: \n");

    while(envp[i]){
                printf("temp[%d] = \"%s\"\n", i, envp[i]);
                i++;
        }

    printf("Sorted environment variables: \n\n");

    bubble_sort(envp, i);
        i = 0;
        while(envp[i]){
                printf("temp[%d] = \"%s\"\n", i, envp[i]);
                i++;
        }
}


void bubble_sort(char *arr[], int size){
    int pass, count; 
    
    void swapping(char **, char **);

    for(pass = 1; pass < size; pass++){
        for(count = 0; count < size -1 ; count++ ){
            if(strcmp(arr[count], arr[count+1]) > 0){
                swapping(&arr[count], &arr[count+1]);
            }     
        }
    }
    
}


void swapping(char **elem1Ptr, char **elem2Ptr){
    char temp = **elem1Ptr;
    **elem1Ptr = **elem2Ptr;
    **elem2Ptr = temp;
}