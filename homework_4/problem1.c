#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

/* Global variables and data in heap are shared by all threads */
void * start_routine(void *id){  /* main func of a thread */
    int *myid = (int *)id;
    /* private data defined in the function if there are any*/

    

    //printf("Greatings from thread %d\n",*myid); 
    pthread_exit(NULL); 
    /*thread ends when pthread_exit is called or the function ends*/ 
}

int main(int argc, char *argv[]){
    
    int NUMINTS, FILESIZE, file;
    char *FILEPATH;
    float *map;
    int j;

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
    NUMINTS = FILESIZE / 4;
    map = mmap(0, FILESIZE, PROT_READ|PROT_WRITE,MAP_SHARED,file,0);

    if(map == MAP_FAILED){
        close(file);
        perror("Error mapping the file");
        exit(0);
    }
    

    return 0;
}