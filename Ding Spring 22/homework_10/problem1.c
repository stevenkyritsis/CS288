//Problem 1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mpi.h"

const int SIZE = 1000;

void countElems(int *counts, int *array_A) {
    int val, i; 
    for(i = 0; i < SIZE; i++){ 
        val=array_A[i]; 
        counts[val]=counts[val]+1; 
    }
}

int main(int argc, char ** argv){
    
    int c;

    int myid,
    numprocs,
    count=0,
    int_arr[SIZE],
    max;
    
    //Open file and gather contents into an array
    FILE *fptr;
    fptr = fopen("/home/Spring2022/sak76/homework_10/file5values", "r");
    while(c = getc(fptr) != EOF){
        int_arr[count] = c;
        count++;
    }
/********************************************************************************/
    //Initialize the MPI
    int numprocs, myid;

    int *buffer = malloc(size * sizeof(int));

    MPI_Init(&argc, &argv);
    
    MPI_Comm_rank(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_size(MPI_COMM_WORLD, &myid);

    MPI_Bcast(&buffer, 1, MPI_UNSIGNED_INT, 0, MPI_COMM_WORLD);

    countElems(buffer, *int_arr);

    //Finished and close MPI
    MPI_Finalize();
    
    printf('%d', &buffer);

    return 0;
}