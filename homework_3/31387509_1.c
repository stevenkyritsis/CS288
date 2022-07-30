#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void radix_sort(float *m, int n, int k);
void reverse_bucket(float *bucket, int b);

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

    radix_sort(map, NUMINTS, 32);

    if(munmap(map, file) == -1){
        perror("Error un-mapping the file");
    }
    close(file);

    return 0;
}

void radix_sort(float *m, int n, int k){
    int index1 = 0, index0 = 0;

    float *bucket0=(float*)malloc(n*sizeof(float));
    float *bucket1=(float*)malloc(n*sizeof(float));

    for(int i=0; i<k; i++){

        for(int j=0; j<n; j++){
        
            unsigned int bit;
            unsigned int num;
            union ufi {
                float f;
                int i;
            }u;

            u.f=m[j];
            num = * (unsigned int *) &m[j];
            bit=(num >> i) & 1;

            if(bit){                
                bucket1[index1] = m[j];
                index1++;
            } else{
                bucket0[index0] = m[j];
                index0++;
            }
        }

        if( i == 31){
            reverse_bucket(bucket1, index1);
            memcpy(m, bucket1, (index1+1)*sizeof(int));
            memcpy(m + index1, bucket0, (index0+1)*sizeof(int));
        } else{
            memcpy(m, bucket0, (index0+1)*sizeof(int));
            memcpy(m + index0, bucket1, (index1+1)*sizeof(int));
        }

        index1 = 0;
        index0 = 0;
    }
}

void reverse_bucket(float *bucket, int b){
    float temp;
    for(int i = 0; i < (b/2); i++){
        temp = bucket[b -1 -i];
        bucket[b-1-i] = bucket[i];
        bucket[i] = temp;
    }
}