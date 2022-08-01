#include <string.h>
#include <stdio.h>

int main(){
	char address[40]="www.auckland.ac.nz";
	char delimiter[2] = ".";
   	char *token;
   	/* get the first part */
   	token = strtok(address, delimiter);
   	/* get the rest */
   	while( token != NULL ) {
      		printf( " %s\n", token );
      		token = strtok(NULL, delimiter);
   	}
   	return(0);
}
