//Inserting a node at the begning of circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* circularsingly(int data);
struct node* addatbeg(struct node* tail,int data);

int main(){
    struct node* tail;

    tail = circularsingly(98);
    tail = addatbeg(tail,45);

    struct node* ptr = tail -> next;

    do{
        printf("%d \n",ptr -> data);
        ptr = ptr -> next;
    }while(ptr != tail -> next);
   
    return 0; 
}
struct node* circularsingly(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
}
struct node* addatbeg(struct node* tail, int data){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp -> data = data;
    newp -> next = tail -> next;
    tail -> next = newp;

    return tail;
}