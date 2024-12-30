#include<stdio.h>
#include<stdlib.h>

struct Node{
    int Data;
    struct Node* next; //self
};
void Ltraversal(struct Node* ptr);
struct Node* IatS(struct Node* head,int data);
struct Node* IatB(struct Node* head,int data,int Index);
struct Node* IatE(struct Node* head,int data);
struct Node* IatN(struct Node* prevNode,int data);
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    head->Data=7;
    head->next=second;
    second->Data=12;
    second->next=third;
    third->Data=21;
    third->next=NULL;
    head=IatS(head,3); //-case1
    Ltraversal(head);
    IatB(head,15,3);
    Ltraversal(head); //-case2
    IatE(head,31);
    Ltraversal(head);
    IatN(second,1);
    Ltraversal(head);
    return 0;
}
void Ltraversal(struct Node* ptr){
while(ptr!=NULL){
    printf("%d ",ptr->Data);
    ptr=ptr->next;
}
printf("\n");
}
struct Node* IatS(struct Node* head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->Data=data;
    ptr->next=head;
    return ptr;
}
struct Node* IatB(struct Node* head,int data,int Index){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->Data=data;
    struct Node* p=head;
    int i=0;
    while(i!=Index-1){
     p=p->next;
     i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return ptr;
}
struct Node* IatE(struct Node* head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->Data=data;
    struct Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return ptr;
}
struct Node* IatN(struct Node* prevNode,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->Data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return ptr;
}
