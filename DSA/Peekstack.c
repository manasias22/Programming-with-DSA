#include<stdio.h>
#include<stdlib.h>
struct Stack{
  int top;
  int size;
  int *arr;
};
void push(struct Stack* ptr,int val){
    if(isFull(ptr)){
        printf("STACK OVERFLOW \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int isEmpty(struct Stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
int isFull(struct Stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
int peek(struct Stack* ptr,int index){
    if(ptr->top-index+1 < 0){
        return -1;
    }
    return ptr->arr[ptr->top-index+1];
}
int stackTop(struct Stack* ptr){
    return ptr->arr[ptr->top];
}
int stackBottom(struct Stack* ptr){
    return ptr->arr[0];
}
int main(){
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    push(s,12);
    push(s,23);
    push(s,34);
    push(s,45);
    for(int i=1;i<=s->top+1;i++){
        printf("PEEK OF ELEMENT %d will be %d \n",i,peek(s,i));
    }
    int o=stackTop(s);
    int p=stackBottom(s);
    printf("VALUES OF TOP AND BOTTOM ARE %d  %d \n",o,p);
    return 0;
}
