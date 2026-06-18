//Inserting a node at a position of a circular doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;

};
struct node* addatempty(int data);
struct node* addatbeg(struct node* tail,int data);
struct node* addatend(struct node* tail,int data);
struct node* addatpos(struct node* tail,int data,int pos);
int print(struct node* tail);
int main(){
    struct  node* tail = NULL;
    tail = addatempty(45);
    tail = addatbeg(tail,98);
    tail = addatend(tail,3);
    tail = addatpos(tail,5,2);
    print(tail);

    return 0;
}
struct node* addatempty(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> prev = temp;
    temp -> data = data;
    temp -> next = temp;

    return temp;
}
struct node* addatbeg(struct node* tail,int data){
    struct node* temp =  tail -> next;
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    newp -> prev = NULL;
    newp -> data = data;
    newp -> next = NULL;

    newp -> prev = tail;
    newp -> next = temp;
    temp -> prev = newp;
    tail -> next = newp;

    return tail;
    }
struct node* addatend(struct node* tail,int data){
    struct node* newp = addatempty(data);
    if(tail == NULL){
        return newp;
    }
    else{
    struct node* temp =  tail -> next;
    newp -> next = temp;
    newp -> prev = tail;
    tail -> next = newp;
    temp -> prev = newp;
    tail = newp;

    return tail;
    }
}
struct node* addatpos(struct node* tail,int data,int pos){
    struct node* newp = addatempty(data);
    if(tail == NULL){
        return newp;
    }
    else{
    struct node* temp =  tail -> next;
    while(pos > 1){
        temp = temp -> next;
        pos --;
    }
    newp -> prev = temp;
    newp -> next = temp -> next;
    temp -> next -> prev = newp;
    temp -> next = newp;
    if(temp == tail){
        tail = tail -> next;
    }

    return tail;
 }
}
int print(struct node* tail){
    if(tail == NULL){
        printf("No element in the list");
    }
    else{
        struct node* temp = tail -> next;
        do{
            printf("%d \n",temp -> data);
            temp = temp -> next;
        }while(temp != tail -> next);

    }
    printf("\n");
}