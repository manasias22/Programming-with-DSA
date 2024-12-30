#include<stdio.h>
#include<stdlib.h>

struct Node{
  int Data;
  struct Node* next; //self repeating loop hai
};
struct Node* deleteatfirst(struct Node* head);
void Ltraversal(struct Node* ptr);
struct Node* deleteatB(struct Node* head,int index);
struct Node* deleteatE(struct Node* head);
struct Node* deleteatK(struct Node* head,int key);
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* forth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    forth=(struct Node*)malloc(sizeof(struct Node));
   
    head->Data=10;
    head->next=second;
    second->Data=22;
    second->next=third;
    third->Data=25;
    third->next=forth;
    forth->Data=31;
    forth->next=NULL;
    
    Ltraversal(head);
    //head=deleteatfirst(head);
    printf("AFTER DELETION \n");
    //Ltraversal(head);
    head=deleteatK(head,22);
    Ltraversal(head);
     // Free the allocated memory
    return 0;
}

void Ltraversal(struct Node* ptr){
    while(ptr!=NULL){
      printf("%d \n",ptr->Data);
      ptr=ptr->next;
    }
}
struct Node* deleteatfirst(struct Node* head){
    struct Node* ptr= head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node* deleteatB(struct Node* head,int index){
    struct Node* ptr=head;
    struct Node* q=head->next;
    int i=0;
    while(i!=index-1){
        ptr=ptr->next;
        q=q->next;
        i++;
    }
    ptr->next=q->next;
    free(q);
    return head;
}

struct Node* deleteatE(struct Node* head){
    struct Node* ptr=head;
    struct Node* q=head->next;
    while(q->next!=NULL){
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=NULL;
    free(q);
    return head;
}
struct Node* deleteatK(struct Node* head,int key){
    struct Node* ptr=head;
    struct Node* q=head->next;
    while(q->Data!=key && q->next!=NULL){
        q=q->next;
        ptr=ptr->next;
    }
    ptr->next=q->next;
    free(q);
    return head;
}
