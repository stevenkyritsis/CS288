//Problem1

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv, char * envp[]){

    int index = 0;
    /*
    while(envp[index]){
        printf("%p",envp[index]);
        index++;
    }*/
	while(envp[index]){
	  printf("envp[%d] = \"%p\"\n", index, envp[index]);
    index++;
	}
	printf("Number of environment vars = %d\n", index );
	exit( 0 );
}