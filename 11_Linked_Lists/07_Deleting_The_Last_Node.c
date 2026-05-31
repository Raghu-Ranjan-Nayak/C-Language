//Deleting the last node from single linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* del_last(struct node *head);
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

    head = del_last(head);
    current = head;
    while(current != NULL){
        printf("%d \n",current -> data);
        current = current -> link;
    }
    return 0;
}
struct node* del_last(struct node *head){
    if(head == NULL){
        printf("list is already empty");
    }
    //check if there is a one node of linked list
    else if(head -> link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp -> link != NULL){
            temp2 = temp;
            temp = temp -> link;
        }
        temp2 -> link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}