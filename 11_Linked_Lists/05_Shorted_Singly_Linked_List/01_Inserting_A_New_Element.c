//Inserting a new element in a shorted singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link; 
};
struct node* addatempty(int data);
struct node* addatend(struct node* head,int data);
struct node* insert(struct node* head,int data);
void print(struct node* head);

int main(){
    struct node* head = NULL;
    head = addatempty(3);
           addatend(head,5);
           addatend(head,98);
    head = insert(head,45);
           print(head);

    return 0;
}
struct node* addatempty(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    return temp;
}
struct node* addatend(struct node* head,int data){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp -> data = data;
    newp -> link = NULL;

    struct node* temp = head;
    while(temp -> link != NULL){
        temp = temp -> link;
    }
    temp -> link = newp;

    return head;
}
struct node* insert(struct node* head,int data){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp -> data = data;
    newp -> link = NULL;

    int key = data;
    struct node* temp = head;
    if(head == NULL || key < head -> data){
        newp -> link = head;
        head = newp;
    }
    else{
        while(temp -> link != NULL && temp -> link -> data < key){
            temp = temp -> link;
            newp -> link = temp -> link;
            temp -> link = newp;  
        }
    }
    return head;
}
void print(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d \n",temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}