//Problem 1

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node { 
    int value; 
    struct node *next; 
};

void writeLL(struct node *head, FILE *wfptr){ //Prints contents of link list
    struct node *p = head;
    while(p != NULL){
        printf("Data entered = %d\n", p->value);
        //fprintf(wfptr,"%d",p->value);
        p = p->next;
    }
}

int main(int argc, char *argv[]){

    int input, 
    flag,
    count = 1;

    struct node *head = NULL, 
    *tail = NULL, 
    *p;

    FILE *fptr;

    fptr = fopen("C:\\Users\\Steven\\Documents\\GitHub\\CS288\\homework_9\\input.txt", "w");

    while(flag != EOF){
        p = (struct node *) malloc(sizeof(struct node));
        printf("Input data %d: ", count);
        flag = scanf("%d", &input);

        p->value = input;
        p->next = NULL;

        if(head == NULL)
            head = p;
        if(tail != NULL)
            tail->next = p;

        tail = p;
        count++;
    }

    writeLL(p,fptr);
    fclose(fptr);

    return 0;
}