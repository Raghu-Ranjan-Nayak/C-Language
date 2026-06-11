//Inserting a node at a certain position of a single linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node* add_at_pos(struct node *head,int pos,int data);
int main(){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = 98;
    ptr -> link = NULL;
    head -> link = ptr;

    ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = 3;
    ptr -> link = NULL;
    head -> link -> link = ptr;

    int pos = 3,data = 67;
    head = add_at_pos(head,pos,data);

    ptr = head;
    while(ptr != NULL){
        printf("%d \n",ptr -> data);
        ptr = ptr -> link;
    }
    return 0;
}
struct node* add_at_pos(struct node *head,int pos,int data){
    struct node *ptr = head;
    struct node *ptr2 = (struct node*)malloc(sizeof(struct node));
    ptr2 -> data = data;
    ptr2 -> link = NULL;

    while(pos != 2){
        ptr = ptr -> link;
        pos--;
    }
    ptr2 -> link = ptr -> link;
    ptr -> link = ptr2;

    ptr = head;
    return head;
}