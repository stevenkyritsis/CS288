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

struct node  *bubbleLL(struct node **head, int count){ //bubbles link list
    for(int i = 0; i < count; i++){
        struct node *active = *head, *next = active->next, *prev = NULL;

        while(next != NULL){
            if(active->value > next->value){
                if(active == *head)
                    *head = next;
                else
                    prev->next = next;
                
                active->next = next->next;
                next->next = active;
                prev = next;
                next = active->next;
            }

            else{
                prev = active;
                active = active->next;
                next = active->next;
            }
        }
    }
    return *head;
}

int main(){
    int count = 1;
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
    p = bubbleLL(&p, count);
    printf("\nThe data sorted:\n");
    displayLL(p);
}