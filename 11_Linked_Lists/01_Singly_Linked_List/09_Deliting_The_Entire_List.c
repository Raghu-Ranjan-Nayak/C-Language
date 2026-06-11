//Deleting the entire single linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* del_list(struct node *head);
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

    head = del_list(head);

    if(head == NULL){
        printf("linked list deleted succesfully");
    }
    return 0;
}
struct node* del_list(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        temp = temp -> link;
        free(head);
        head = temp;
    }
    return head;
}
