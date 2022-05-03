#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int myid[100];
int N, Nthreads;  
double sum[100], h;  
pthread_t tid[200];

void *mycpi(void *arg) {
  int myrank, i, j;    
  double x;  
  myrank = *(int *)arg;
  h = 1.0 / (double) N;
  sum[myrank] = 0.0;
  for(i=N/Nthreads*myrank+1; i<= N/Nthreads*(myrank+1);
      i ++) {
    x = h * ((double)i - 0.5);
    sum[myrank] += 4.0 / (1.0 + x*x);
  }
}

int main(int argc, char *argv[]) {
  int i;
  double PI25DT = 3.141592653589793238462643;
  double mypi, pi, x, a;
  N = atoi(argv[1]);
  Nthreads = 4;
  for (i=0; i<Nthreads; i++) {
    myid[i] = i;
    pthread_create(&tid[i], NULL, &mycpi, &myid[i]);
  } 
  for (i=0; i<Nthreads; i++) pthread_join(tid[i], NULL);
  mypi = 0;
  for (i=0; i<Nthreads; i++) mypi += 1.0 / (double) N * sum[i];
  printf("pi is approximately %.16f, Error is %.16f\n",
          mypi, fabs(mypi - PI25DT));
}
