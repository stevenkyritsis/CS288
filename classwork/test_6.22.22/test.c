#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ){
	int res=0, i;
	if (argc != 3){
		printf("Usage: ./program 1 2\n");
		return -1;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	for (i = 1; i < --argc; i--){
		res ^= atoi(argv[argc]);
		printf("Swap %d: %d \n", i, res);
	}

	return 0;
}
