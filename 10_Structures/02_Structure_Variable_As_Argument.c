//print values by structure
//Passes structure variable as argument
#include<stdio.h>
struct point{
    int x;
    int y;
};
void print(struct point p){
    printf("%d %d \n",p.x,p.y);
}
int main(){
    struct point p1={34,56};
    struct point p2={45,67};
    print(p1);
    print(p2);
    return 0;
}