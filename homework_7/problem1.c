//Problem 1

#include<stdlib.h>
#include<stdio.h>

struct node{
    int value;
    struct node *next;
};

int main(){
    struct node *head, *tail, *p;
    struct node input;

    p=(struct node *)malloc(sizeof(struct node));

    while(true){
        int i = 1;
        printf("Input data for node %d", i);
        scanf("%d", input); 
        
        p->value = input;
        if (i == 1){
            head->value = input;
            head->next = p->next;
        }
        if (){
            
        }
       
    };
    

    return 0;
}