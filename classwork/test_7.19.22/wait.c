#include <stdio.h>
#include <stdlib.h>
int main(){
	int pid, status, childPid;
	pid = fork();
	if ( pid != 0 ) {
		printf("Parent process: %d, PPID %d\n", getpid(), getppid());
		childPid=wait(&status); //wait for a child to terminate.
		printf("A child with PID %d terminated with exit code %d \n", childPid, status >> 8);
	}
	else {
		printf("Child process PID: %d, PPID %d \n", getpid(), getppid());
		exit(42);
	}
	printf("PID %d terminates \n", getpid());
	return 0;
}
