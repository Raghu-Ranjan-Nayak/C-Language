//Create a polynomial by using application of linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    float coff;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head,float coff,int expo);
struct node* create(struct node* head);
void print(struct node* head);
int main(){
    struct node* head = NULL;
    printf("Enter the polynomial \n");
    head = create(head);
    print(head);

    return 0;
}
struct node* insert(struct node* head,float co,int ex){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    newp -> coff = co;
    newp -> expo = ex;
    newp -> link = NULL;

    if(head == NULL || ex > head -> expo){
        newp -> link = head;
        head = newp;
    }
    else{
        temp = head;
        while(temp -> link != NULL && temp -> link -> expo >= ex){
            temp = temp -> link;
        }
        newp -> link = temp -> link;
        temp -> link = newp;
    }
    return head;
}
struct node* create(struct node* head){
    int n;
    float coff;
    int expo;

    printf("Enter the number of terms:");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        printf("Enter the coffecent of the term %d:",i+1);
        scanf(" %f", &coff);

        printf("Enter the exponent of the term %d:",i+1);
        scanf(" %d", &expo);

        head = insert(head,coff,expo);
    }
    return head;
}
void print(struct node* head){
    if(head == NULL){
        printf("no polynomial");
    }
    else{
        struct node* temp = head;
        while(temp != NULL){
            printf("(%.1fx^%d)",temp -> coff,temp -> expo);
            temp = temp -> link;
            if(temp != NULL){
                printf("+");
            }
            else{
                printf("\n");
            }
        }

    }
    
}
