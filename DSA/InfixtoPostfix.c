#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack{
    int Top;
    int size;
    int *arr;
};
int Precedence(char ch){
    if(ch=='*' || ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}
int isOperator(char ch){
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-'){
        return 1;
    }
    return 0;
}
char StackTop(struct Stack* ptr){
    return ptr->arr[ptr->Top];
}
int isFull(struct Stack* ptr){
    if(ptr->Top==ptr->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(struct Stack* ptr){
    if(ptr->Top==-1){
        return 1;
    }
    return 0;
}
void push(struct Stack* ptr,char val){
    if(isFull(ptr)){
        printf("STACK OVERFLOW \n");
    }
    ptr->Top++;
    ptr->arr[ptr->Top]=val;
}
char pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("STACK UNDERFLOW \n");
        return -1;
    }
    char val=ptr->arr[ptr->Top];
    ptr->Top--;
    return val;
}
char *infixtopostfix(char *infix){
    struct Stack* sp=(struct Stack*)malloc(sizeof(struct Stack));
    sp->size=100;
    sp->Top=-1;
    sp->arr=(char*)malloc(sp->size * sizeof(char));
    char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(Precedence(infix[i])>Precedence(StackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    return postfix;
}
int main(){
    char *exp="a-b+t/6";
    char *thp=infixtopostfix(exp);
    printf("%s",thp);
    return 0;
}
