#include<stdio.h>
#include<stdlib.h>
struct Node{
  int Data;
  struct Node* next;
};
struct Node* front=NULL;
struct Node* rear=NULL;
void LTraversal(struct Node* ptr){
    while(ptr->next!=NULL){
        printf("%d  ",ptr->Data);
        ptr=ptr->next;
    }
     printf("%d  \n",ptr->Data);
}
void enqueue(int val){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("QUEUE OVERFLOW \n");
    }
    else{
        n->Data=val;
        n->next=NULL;
        if(front==NULL){
            front=rear=n;
        }
        else{
            rear->next=n;
            rear=n;
        }
    }
}
int dequeue(){
    struct Node* ptr=front;
    int val=-1;
    if(front==NULL){
        printf("QUEUE UNDERFLOW \n");
    }
    else{
     front=front->next;
     val=ptr->Data;
    }
    return val;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    LTraversal(front);
    dequeue();
    dequeue();
    LTraversal(front);
    return 0;
}
