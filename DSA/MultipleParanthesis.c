#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int top;
    int size;
    char *arr;
};
int match(char a,char b){
    if(a=='(' && b== ')'){
        return 1;
    }
    if(a=='[' && b== ']'){
        return 1;
    }
    if(a=='{' && b== '}'){
        return 1;
    }
    return 0;
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
void push(struct Stack* ptr,char val){
    if(isFull(ptr)){
        printf("THE STACKOVERFLOW \n");
    }
    ptr->top++;
    ptr->arr[ptr->top]=val;
}
char pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("STACK UNDERFLOW \n");
        return '\0';
    }
    char val=ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
int Paranthesis(char *exp){
    struct Stack* sp=(struct Stack*)malloc(sizeof(struct Stack));
    sp->top=-1;
    sp->size=100;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char poppedelement;
    for(int i=0; exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=="["){
            push(sp,exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]=="]"){
            if(isEmpty(sp)){
                return 0;
            }
             poppedelement=pop(sp);
            if(!match(poppedelement,exp[i])){
                return 0;
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    return 0;
}
int main(){
    char * exp= "{{2*[2]8+1}";
    if(Paranthesis(exp)){
        printf("PERFECT BALANCED EQUATION");
    }
    else{
        printf("Improper Equation");
    }
    return 0;
}