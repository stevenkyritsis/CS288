#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node { 
 int value; 
 struct node *next; 
};

void displayLL(struct node *head){ //Prints contents of link list
    struct node *p = head;

    while(p != NULL){
        printf("Data = %d\n", p->value);
        p = p->next;
    }
}

void reverseLL(struct node **head){ //reverses link list
    struct node *prev = NULL, *active = *head, *next = NULL;
    
    while(active != NULL){
        next = active->next;
        active->next = prev;
        prev = active;
        active = next;
    }
    *head = prev;
}

int main(){
    int count = 1, it;
    struct node *head = NULL, *tail = NULL, *p;

    for(;;){
        p = (struct node *) malloc(sizeof(struct node));
        printf("Input data for node %d: ", count);

        if(scanf("%d", &(p->value)) == EOF) 
            break;

        p->next = NULL;

        if(head == NULL)
            head = p;
        if(tail != NULL)
            tail->next = p;

        tail = p;
        count++;
    }

    p = head;
    
    printf("\n\nData entered in the list are:\n");
    displayLL(p);
    reverseLL(&p);
    printf("\nThe data list in reverse is:\n");
    displayLL(p);
}