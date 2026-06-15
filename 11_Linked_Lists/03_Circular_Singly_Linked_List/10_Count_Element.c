//Count elements of a circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* addatempty(int data);
struct node* addatend(struct node* tail,int data);
void countelement(struct node* tail);

int main(){
    struct node* tail = NULL;
    int pos =3;
    
    tail = addatempty(98);
    tail = addatend(tail,45);
    tail = addatend(tail,3);
    countelement(tail);

    struct node* ptr = tail -> next;

    do{
        printf("%d \n",ptr -> data);
        ptr = ptr -> next;
    }while(ptr != tail -> next);
   
    return 0; 
}
struct node* addatempty(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
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
void countelement(struct node* tail){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int count = 0;
    temp = tail -> next;
    while(temp != tail){
        count++;
        temp = temp -> next;
    }
    count++;
    printf("There are %d elements in the list: \n",count);
}