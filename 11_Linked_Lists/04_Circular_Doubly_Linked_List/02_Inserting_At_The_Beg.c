//Inserting a node at the begning of a circular doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;

};
struct node* addatempty(int data);
int print(struct node* tail);
struct node* addatbeg(struct node* tail,int data);

int main(){
    struct  node* tail = NULL;
    tail = addatempty(98);
    tail = addatbeg(tail,45);
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
    struct node* newp = addatempty(data);
    if(tail == NULL){
        return newp;
    }
    else{
    struct node* temp =  tail -> next;
    newp -> prev = tail;
    newp -> next = temp;
    temp -> prev = newp;
    tail -> next = newp;

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