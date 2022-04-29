//Problem 1

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<mpi.h>

int main(int argc, char ** argv){
    
    unsigned int c;

    FILE *fptr;

    fptr = fopen("/home/Spring2022/sak76/homework_10/file5values", "r");

    while(c = getc(fptr) != EOF){
        
    }

    int rank, size;

    MPI_Init(&argc, &argv);
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("I am %d of %d", rank + 1, size);

    MPI_Finalize();
    
    return 0;
}