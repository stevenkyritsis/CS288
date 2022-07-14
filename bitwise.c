#include <stdio.h>

int main(){

	char a = 24;
	int i;

	for(i=0; i<sizeof(a)*8; i++){
		printf("%d", (a & 0x80)>>7);
		a=a<<1;
	}

	return printf("\n");
}
