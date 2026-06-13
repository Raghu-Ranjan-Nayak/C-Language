//Inserting a node between the nodes of a circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* circularsingly(int data);
struct node* addatbeg(struct node* tail,int data);
struct node* addatend(struct node* tail,int data);
struct node* addatpos(struct node* tail,int data,int pos);

int main(){
    struct node* tail;
    int pos = 2;

    tail = circularsingly(98);
    tail = addatbeg(tail,45);
    tail = addatend(tail,3);
    tail = addatpos(tail,5,pos);

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
struct node* addatend(struct node* tail,int data){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp -> data = data;
    newp -> next = NULL;

    newp -> next = tail -> next;
    tail -> next = newp;
    tail = tail -> next;

    return tail;
}
struct node* addatpos(struct node* tail,int data,int pos){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp -> data = data;
    newp -> next = NULL;

    struct node* temp;
    temp = tail -> next;
    while(pos > 1){
        temp = temp -> next;
        pos --;
    }
    newp -> next = temp -> next; 
    temp -> next = newp;

    if(temp == tail){
        tail = tail -> next;
    }
   
    return tail;
    
}