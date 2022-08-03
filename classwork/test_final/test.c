#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	int pipefd_1[2], pipefd_2[2];
	int i, status;

	/*create two pipes*/
	pipe(pipefd_1);
	pipe(pipefd_2);

	if(!fork()){ //launch find
		//setting up one end of the pipe connecting to sort
		close(0);
		dup(pipefd_2[1]);	
		//close unneeded read/write ends of the pipes
		close(pipefd_1[0]);
		close(pipefd_2[0]); close(pipefd_2[1]);
		execlp("find","find","/bin","-type","f",NULL);

	}
	if(!fork()){ //launch sort
		//setting up the end of the pipe connecting to find
		dup(pipefd_2[1]);
		close(pipefd_1[1]);
		//setting up the end of the pipe connecting to head
		close(1);
		dup(pipefd_2[1]);
		//close unused ends of the pipes
		close(pipefd_2[0]);
		close(pipefd_2[1]);
		execlp("sort","sort","-k","1.1n","-k","2.2",NULL);
	}

	close(pipefd_1[0]); close(pipefd_2[0]);
	close(pipefd_1[1]); close(pipefd_2[1]);

	//parent should not finish before children
	for(i=0; i<3; i++) wait(&status);
	//wait(&status);
	return 0;
}
