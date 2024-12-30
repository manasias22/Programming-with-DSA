#include<stdio.h>
#include<stdlib.h>
struct Node{
    int Data;
    struct Node* next;
};
void Ltraversal(struct Node* ptr);
struct Node* insertionatS(struct Node* head,int Data);
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    head->Data=4;
    head->next=second;
    second->Data=10;
    second->next=third;
    third->Data=21;
    third->next=head;
    head=insertionatS(head,1);
    Ltraversal(head);
    return 0;
}
void Ltraversal(struct Node* head){
    struct Node* ptr=head;
    do{
       printf("%d ",ptr->Data);
       ptr=ptr->next;
    }while(ptr->next!=head);
    printf("%d",ptr->Data);
}
struct Node* insertionatS(struct Node* head,int Data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->Data=Data;
    struct Node* p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return ptr;
}







