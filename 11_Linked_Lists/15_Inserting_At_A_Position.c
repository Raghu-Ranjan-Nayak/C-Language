//Inserting a node at position 2 of a doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* addtoempty(struct node* head,int data);
struct node* addatbeg(struct node* head,int data);
struct node* addatend(struct node* head,int data);
struct node* addatpos(struct node* head,int data,int position);
int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* ptr;
    int position = 2;

    head = addtoempty(head,45);
    head = addatbeg(head,98);
    head = addatend(head,3);
    head = addatpos(head,5,position);

    ptr = head;
    while(ptr != NULL){
        printf("%d \n",ptr -> data);
        ptr = ptr -> next;
    }
    return 0;
}

struct node* addtoempty(struct node* head,int data){
     struct node* temp = (struct node*)malloc(sizeof(struct node));
     temp -> prev = NULL;
     temp -> data = 45;
     temp -> next = NULL;
     head = temp;
     return head;
}
struct node* addatbeg(struct node* head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = 98;
    temp -> next = NULL;
    temp -> next = head;
    head -> prev = temp;
    head = temp;

    return  head;
}
struct node* addatend(struct node* head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* temp1;
    temp1 = head;
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    while(temp1 -> next != NULL){
        temp1 = temp1 -> next;
    }
    temp1 -> next = temp;
    temp -> prev = temp1;

    return head;
}
struct node* addatpos(struct node* head,int data,int position){
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    struct node* temp2;
    temp = head;
    temp1 -> prev = NULL;
    temp1 -> data = data;
    temp1 ->next = NULL;
    while(position != 1){
        temp = temp -> next;
        position --;
    }
    if(temp -> next == NULL){
        temp -> next = temp1;
        temp1 -> prev = temp;
    }
    else{
    temp2 = temp -> next;
    temp -> next = temp1;
    temp2 -> prev = temp1;
    temp1 -> prev = temp;
    temp1 -> next = temp2;
    }
    return head;
}