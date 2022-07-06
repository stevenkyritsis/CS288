#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

/* Global variables and data in heap are shared by all threads */
void * start_routine(void *id){  /* main func of a thread */
    int *myid = (int *)id;
    /* private data defined in the function if there are any*/

    printf("Greatings from thread %d\n",*myid); 
    pthread_exit(NULL); 
    /*thread ends when pthread_exit is called or the function ends*/ 
}

int main(int argc, char *argv[]) { 
   /* main thread creates and controls new threads*/
    pthread_t thread[10]; int ret, i, index[10];
    for (i=0;i<10;i++){
        index[i] = i;
        ret = pthread_create(thread+i,NULL,start_routine,&(index[i]));
        if (ret!=0) { errno = ret; perror("pthread_create"); return -1;}
    }
    for (i=0;i<10;i++) pthread_join(thread[i], NULL);

    return 0;
}
