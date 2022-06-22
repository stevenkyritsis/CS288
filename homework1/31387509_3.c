//Steven Kyritsis
//NJIT CS288-032 Professor Weiwei

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Problem 3: File (HDD) Access Delay
int main(){

    clock_t start, end;
    FILE *file_read;
    const int CACHE_SIZE = 47104;
    double latency_access_time;

/*
    file_read = fopen("/home/sak76/homework/homework_1/test.txt", "w");
    fprintf(file_read,"Hello World!\n");
    
    for(int i = 0; i < 1024 * 1024; i++){
        fprintf(file_read,"Hello World!");
    }
    fclose(file_read);
*/

   int *arr=(int*)malloc(CACHE_SIZE * sizeof(int));
    for (int i=0; i < CACHE_SIZE; i++){
        arr[(i)];
    }

    for(int j = 0; j < 4; j++){
        start = clock();
        for (int count=0; count < 100; count++){
            file_read = fopen("/home/sak76/homework/homework_1/test.txt", "r");   
        }
        end = clock();
        latency_access_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("The access time for HDD for loop %d: %.10fs\n",j,latency_access_time);

        fclose(file_read);
    }

    return 0;
}
