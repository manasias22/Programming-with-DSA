#include<stdio.h>
#include<stdlib.h>
struct Node{
    int Data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int Data){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->Data=Data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void PreOrder(struct Node* root){
    if(root!=NULL){
        printf("    %d     ",root->Data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int isBST(struct Node* root){
    static struct Node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->Data <= prev->Data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

void insert(struct Node* root,int key){
  struct Node* prev=NULL;
  while(root!=NULL){
      prev=root;
      if(key==root->Data){
          return;
      }
      else if(key<root->Data){
          root=root->left;
      }
      else{
          root=root->right;
      }
  }
  struct Node* n=createNode(key);
  if(prev->Data<key){
      prev->right=n;
  }
  else{
      prev->left=n;
  }
}
int main(){
    struct Node* p=createNode(8);
    struct Node* p1=createNode(3);
    struct Node* p2=createNode(10);
    struct Node* p3=createNode(1);
    struct Node* p4=createNode(6);
    struct Node* p5=createNode(4);
    struct Node* p6=createNode(7);
    struct Node* p7=createNode(14);
    struct Node* p8=createNode(13);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p4->left=p5;
    p4->right=p6;
    p2->right=p7;
    p7->left=p8;
    if(isBST(p)){
        printf("TREE IS BST TREE \n ");
    }
    insert(p,9);
    PreOrder(p);
    return 0;
}
