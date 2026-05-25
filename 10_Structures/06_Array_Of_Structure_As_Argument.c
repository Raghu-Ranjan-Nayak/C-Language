//Passes array of structure as argument
#include<stdio.h>
struct point{
    int x;
    int y;
};
void print(struct point arr[]){
    for(int i=0;i<2;i++){
    printf("%d %d \n",arr[i].x,arr[i].y);
    }
}
int main(){
    struct point arr[2]={{4,6},{3,7}};
    print(arr);
    return 0;
}