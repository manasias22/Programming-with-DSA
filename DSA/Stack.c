#include<stdio.h>
#include<stdlib.h>
struct Stack{
  int size;
  int top;
  int *arr;
};

int isEmpty(struct Stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}
int isFull(struct Stack* ptr){
    if(ptr->top== ptr->size-1){
        return 1;
    }
    return 0;
}

int main(){
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size=80;
    s->top=-1;
    s->arr=(int*)malloc(s->size* sizeof(int));
    
     s->arr[0]=7;
     s->top++;
    int index=isEmpty(s);
    if(index==1){
        printf("THE STACK IS EMPTY");
    }
    else{
        printf("The stack is not empty");
    }
    return 0;
}
