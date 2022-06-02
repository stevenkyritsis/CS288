//Problem 2

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node { 
    int value; 
    struct node *next; 
};

int main(){

    unsigned int c;
    FILE *tfile, *bfile;
    tfile = fopen("C:\\Users\\Steven\\Documents\\GitHub\\CS288\\homework_9\\input.txt", "r");
    bfile = fopen("C:\\Users\\Steven\\Documents\\GitHub\\CS288\\homework_9\\input.bin", "w");
    if (tfile) {
        while ((c = getc(tfile)) != EOF){
            putchar(c);
            fwrite(c,sizeof(c),1,bfile);
        }
            
        fclose(tfile);
        fclose(bfile);
    }

    return 0;

}