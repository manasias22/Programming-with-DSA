#include<stdio.h>
#include<stdlib.h>

struct Node{
  int Data;
  struct Node* next; //self repeating loop hai
};

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
   
    head->Data=10;
    head->next=second;
    second->Data=22;
    second->next=third;
    third->Data=25;
    third->next=NULL;
    
    traversal(head);
    
     // Free the allocated memory
    free(head);
    free(second);
    free(third);
    return 0;
}

void traversal(struct Node* ptr){
    while(ptr!=NULL){
      printf("%d \n",ptr->Data);
      ptr=ptr->next;
    }
}

