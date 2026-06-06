//Deling the last node of a doubly linked list
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
struct node* dellast(struct node* head);
int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* ptr;
    struct node* temp2 = NULL;
    struct node* temp3 = NULL;

    head = addtoempty(head,45);
    head = addatbeg(head,98);
    head = addatend(head,3);
    head = dellast(head);
    
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
struct node* dellast(struct node* head){
    struct node* temp = head;
    struct node* temp2;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp2 = temp -> prev;
    temp2 -> next = NULL;
    free(temp);
    temp = NULL;
    
    return head;
}