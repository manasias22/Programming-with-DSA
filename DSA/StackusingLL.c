#include<stdio.h>
#include<stdlib.h>
struct Node{
int Data;
struct Node* next;
};
struct Node* Top=NULL;
int IsEmpty(struct Node* Top){
if(Top==NULL){
return 1;
}
return 0;
}
int IsFull(struct Node* Top){
struct Node* n=(struct Node*)malloc(sizeof(struct Node));
if(n==NULL){
return 1;
}
return 0;
}
struct Node* push(struct Node* Top,int Data){
if(IsFull(Top)){
printf("StackOverflow \n");
}
struct Node* n=(struct Node*)malloc(sizeof(struct Node));
n->Data=Data;
n->next=Top;
Top=n;
return Top;
}
int pop(){
if(IsEmpty(Top)){
printf("STACK UNDERFLOW \n");
return;
}
struct Node* n=Top;
Top=Top->next;
int val=n->Data;
free(n);
return val;
}
void LTraversal(struct Node *ptr)
{
while (ptr != NULL)
{
printf("Element: %d\n", ptr->Data);
ptr = ptr->next;
}
}

int main(){
Top=push(Top,12);
Top=push(Top,23);
Top=push(Top,45);
LTraversal(Top);
int val=pop();
printf("POPPED ELEMENT OF STACK IS %d \n",val);
Top=push(Top,24);
LTraversal(Top);
return 0;
}
