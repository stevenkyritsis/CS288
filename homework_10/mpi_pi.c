#include "mpi.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int myid, numprocs, i;
    unsigned long n;
    long double PI = 3.14159265358979323846264338327950288419716939937510;
    long double pi, sum, partial_sum, x;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    if (myid == 0) {
        printf("Enter the number of terms:");
        scanf("%lu",&n);
    }
    MPI_Bcast(&n, 1, MPI_UNSIGNED_LONG, 0, MPI_COMM_WORLD);
    
    partial_sum = 0.0;
    for(i=n/numprocs*myid+1; i<= n/numprocs*(myid+1); i++) {
        x = ((double)i - 0.5)/n;
        partial_sum+= 4.0 / (1.0 + x*x);
    }

    MPI_Reduce(&partial_sum, &sum, 1, MPI_LONG_DOUBLE, MPI_SUM, 0,
                   MPI_COMM_WORLD);

    if (myid == 0){
        pi = sum/n;
        printf("pi is approximately %.22Lf, Error is %.22Lf\n",  
		pi, fabsl(pi - PI));
    }
    MPI_Finalize();
    return 0;
}
