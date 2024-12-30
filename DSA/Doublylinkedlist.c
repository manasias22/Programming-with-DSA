#include<stdio.h>
#include<stdlib.h>
struct Node{
  struct Node* prev;
  int Data;
  struct Node* next;
};
void Ltraversal(struct Node* ptr);
struct Node* IatS(struct Node* head,int Data);
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* forth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));
    head->prev=NULL;
    head->Data=23;
    head->next=second;
    second->prev=head;
    second->Data=45;
    second->next=third;
    third->prev=second;
    third->Data=56;
    third->next=forth;
    forth->prev=third;
    forth->Data=65;
    forth->next=NULL;
    head=IatS(head,12);
    Ltraversal(head);
    return 0;
}
void Ltraversal(struct Node* ptr){
    while(ptr->next!=NULL){
        printf("%d  ",ptr->Data);
        ptr=ptr->next;
    }
    printf("%d  ",ptr->Data);
}

struct Node* IatS(struct Node* head,int Data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->Data=Data;
    ptr->prev=NULL;
    ptr->next=head;
    head->prev=ptr;
    return ptr;
}
