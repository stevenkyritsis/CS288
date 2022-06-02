//Problem 1

#include<stdlib.h>
#include<stdio.h>
#include<memory.h>

struct node{
    int value;
    struct node *next;
};

int main(){

    struct node *head=NULL, *p, *tail=NULL;

    int i = 1, input;
    while(i <= 3){
        p=malloc(sizeof(struct node));

        printf("Input data for node %d: ", i);
        p->value = scanf("%d", &input);
        if (scanf())
        if (i == 1) {
            tail->next = NULL;
            tail->value = p->value;
                 
            head->value = tail->value;
            head->next = tail->next;
        };
        //Assigning the head to the value initialized in p
        if (i > 1){
            head->value = p->value;
            head->next = p; 
            p->next = tail;
        }
        
        ++i;
    };

    printf("The result is:\n");
    p->value = head->value;
    printf("This is 1: %d \n", p->value);
    p=head->next;
    printf("This is 2: %d", p->value);
    p=p->next;
    printf("This is 3: %d", p->value);

    return 0;
}

void show_list(struct node *head) {
    struct node *p=head;
    if(head==NULL) return;
    while(p!=NULL){
            printf("->%d", p->value);
            p=p->next;
    }
    printf("\n");
} 