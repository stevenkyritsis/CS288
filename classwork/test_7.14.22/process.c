#include <stdio.h>
int main() {
	int pid;

	printf("Parent PID: PID %d, PPID %d.\n", getpid(), getppid());
	pid = fork();

	if (pid!=0) {
		printf("Parent: PID %d, PPID %d.\n", getpid(), getppid());
		printf("My child's PID is %d \n", pid);
	}
	else{
		printf("Child: PID %d, PPID %d.\n", getpid(), getppid());
		printf("PID VALUE: %d \n", pid); //added to see the pid value in a child process
	}

	printf("PID %d terminates.\n", getpid());

	return 0;
}
