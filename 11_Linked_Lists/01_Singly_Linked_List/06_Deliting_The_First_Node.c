//Deleting the first node from single linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* del_first(struct node *head);
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current -> data = 98;
    current -> link = NULL;
    head -> link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current -> data = 3;
    current -> link = NULL;
    head -> link -> link = current;

    current = (struct node*)malloc(sizeof(struct node));
    current -> data = 5;
    current -> link = NULL;
    head -> link -> link -> link = current;
     

    head = del_first(head);
    current = head;

    while(current != NULL){
        printf("%d \n",current -> data);
        current = current -> link;
    }
    return 0;
}
struct node* del_first(struct node *head){
    if(head == NULL){
        printf("list is already empty");
    }
    else{
    struct node *temp;
    temp = head;
    head = head -> link;
    free(temp);
    temp = NULL;
    }

    return head;
}