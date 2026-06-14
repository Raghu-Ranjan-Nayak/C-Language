//Deliting the first node of a circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* addtempty(int data);
struct node* addatend(struct node* tail,int data);
struct node* creatinglist(struct node* tail);
struct node* delfirst(struct node* tail);

int main(){
    struct node* tail = NULL;
    
    tail = creatinglist(tail);
    tail = delfirst(tail);

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
struct node* creatinglist(struct node* tail){
    int i,n,data;
    printf("Enter number of nodes of the linked list:");
    scanf("%d",&n);

    if(n == 0){
        return tail;
    }
    else{
        printf("Enter the elements of node 1:");
        scanf("%d",&data);
        tail = addatempty(data);

        for(i = 1 ; i < n ; i++){
            printf("Enter the elements of node %d:",i+1);
            scanf("%d",&data);
            tail = addatend(tail,data);
            
        }
    }
    return tail;
}
struct node* delfirst(struct node* tail){
    if(tail == NULL){
        return tail;
    } 
    if(tail -> next == NULL){
        free(tail);
        tail = NULL;
    }
    else{
        struct node* temp;
        temp = tail -> next;
        tail -> next = temp -> next;
        free(temp);
        temp = NULL;
    }
        return tail;
}