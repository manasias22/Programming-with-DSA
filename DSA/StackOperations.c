#include<stdio.h>
#include<stdlib.h>
struct Stack{
  int size;
  int top;
  int *arr;
};
int IsEmpty(struct Stack* ptr){
    if(ptr->top== -1){
        return 1;
    }
    return 0;
}
int IsFull(struct Stack* ptr){
    if(ptr->top== ptr->size-1){
        return 1;
    }
    return 0;
}
void push(struct Stack* ptr,int val){
    if(IsFull(ptr)){
        printf("STACK OVERFLOW \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct Stack* ptr){
    if(IsEmpty(ptr)){
        printf("Stack Underflow");
        return 0;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*)malloc(s->size* sizeof(int));
    push(s,12);
    push(s,21);
    push(s,31);
    push(s,41);
    push(s,51);
    push(s,61);
    push(s,71);
    push(s,81);
    push(s,91);
    push(s,101);
    printf("%d",IsFull(s));
    int val=pop(s);
    printf("POPPED OUT THE VALUE--> %d ",val);
    return 0;
}
