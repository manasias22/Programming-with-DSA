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
int isBST(struct Node* root){
    static struct Node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->Data <=prev->Data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    struct Node* p=createNode(9);
    struct Node* p1=createNode(4);
    struct Node* p2=createNode(11);
    struct Node* p3=createNode(2);
    struct Node* p4=createNode(7);
    struct Node* p5=createNode(5);
    struct Node* p6=createNode(8);
    struct Node* p7=createNode(15);
    struct Node* p8=createNode(14);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p4->left=p5;
    p4->right=p6;
    p2->right=p7;
    p7->left=p8;
    int a=isBST(p);
    if(a){
      printf("THE ELEMENT IS BST TREE");   
    }
    else{
         printf("THE ELEMENT IS NOT BST TREE");
    }
    return 0;
}
