//Multiply two polynomial by using application of linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    float coff;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head,float coff,int expo);
struct node* create(struct node* head);
void polymul(struct node* head1,struct node* head2);
void print(struct node* head3);
int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    printf("Enter the polynomial 1 \n");
    head1 = create(head1);

    printf("Enter the polynomial 2 \n");
    head2 = create(head2);

    polymul(head1,head2);

    return 0;
}
struct node* insert(struct node* head,float co,int ex){
    struct node* newp = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    newp -> coff = co;
    newp -> expo = ex;
    newp -> link = NULL;

    //if there is no node in the list  or given exponent is greater than exponent of first node 
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
void print(struct node* head3){
    if(head3 == NULL){
        printf("no polynomial");
    }
    else{
        struct node* temp = head3;
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

void polymul(struct node* head1,struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    //check if first or second node is null
    if(head1 == NULL && head2 == NULL){
        printf("zero polynomial \n");
        return;
    }
    
    while(ptr1 != NULL){
        ptr2 = head2;
        while(ptr2 != NULL){
            head3 = insert(head3,ptr1 -> coff * ptr2 -> coff,ptr1 -> expo + ptr2 -> expo);
            ptr2 = ptr2 -> link;
        }
        ptr1 = ptr1 -> link;
    }
    printf("\n before simplification \n");
    print(head3);

    //Adding the like terms(terms with same exponent) for simplification
    struct node* ptr3 = head3;
    struct node* temp = NULL;

    while(ptr3 -> link != NULL){
        if(ptr3 -> expo == ptr3 -> link -> expo){
            ptr3 -> coff = ptr3 -> coff + ptr3 -> link -> coff; 
            temp = ptr3 -> link;
            ptr3 -> link = ptr3 -> link -> link;
            free(temp);
        
        }
        else{
        ptr3 = ptr3 -> link;
        }

    }
     printf("\n aftter simplification \n");
     print(head3);


}
