#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
	if(fork() == 0){
		int ret = execlp("ls", "ls", "/home/sak76/", NULL);
		perror("execlp");
		exit(1);
	}
	
	wait();
	printf("Child process complete.\n");

	return 0;
}
