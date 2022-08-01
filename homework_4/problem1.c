#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>
int Nthreads = 2;

//global float variable for the mapped file
float *map;

/* Global variables and data in heap are shared by all threads */
void * start_routine(void *id){  /* main func of a thread */
    int *myid = (int *)id;
    /* private data defined in the function if there are any*/

    int i=0;
    while(map[i] != 0){
        printf("%f\n %d\n",map[i], *myid);
        i++;
    }

    //printf("Greatings from thread %d\n",*myid); 
    pthread_exit(NULL); 
    /*thread ends when pthread_exit is called or the function ends*/ 
}

int main(int argc, char *argv[]){
    
    int NUMOBJ, FILESIZE, file;
    char *FILEPATH;

    //Checking for 2 arguments
    if (argc < 2){
        printf("Error! Not enough arguments.\n");
        exit(0);
    }
    
    FILEPATH=argv[1];

    //Creating a file pointer named fp
    file = open(FILEPATH, O_RDWR, (mode_t)0600);

    //Error checking file open
    if(file== -1){
        perror("Error open");
        exit(0);
    }

    FILESIZE = lseek(file,0,SEEK_END);
    NUMOBJ = FILESIZE / 4;
    map = mmap(0, FILESIZE, PROT_READ|PROT_WRITE,MAP_SHARED,file,0);

    if(map == MAP_FAILED){
        close(file);
        perror("Error mapping the file");
        exit(0);
    }


    pthread_t thread[10]; int ret, index[10];
    for(int i = 0; i < 10; i++){
        ret = pthread_create(thread+i,NULL,start_routine,&(index[10]));
        if (ret!=0) { errno = ret; perror("pthread_create"); return -1;}
    }
    for (int i=0;i<10;i++) pthread_join(thread[i], NULL);
    /*
    int i=0;
    while(map[i] != 0){
        printf("%f",map[i]);
        i++;
    }*/

    return 0;
}