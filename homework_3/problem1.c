#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int radix_sort(int,int,int);

int main(int argc, char *argv[]){

    if (argc < 2){
        printf("Error! Not enough arguments.\n");
        return 0;
    }

    

    return 0;
}

int radix_sort(int a, int n, int k){
    int bucket0[], bucket1[], bucket_merge[];

    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            bit = a[i] >> 1;
            if (bit = 1) bucket1[i] = a[i];
            else bucket0[i] = a[i];
        }
    }
}