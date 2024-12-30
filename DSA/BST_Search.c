#include<stdio.h>
#include<stdlib.h>
struct Node{
    int Data;
    struct Node* left;
    struct Node* right;
};
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

struct Node* BinarySearchTree(struct Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->Data==key){
        return root;
    }
    else if(root->Data > key){
        return BinarySearchTree(root->left,key);
    }
    else{
        return BinarySearchTree(root->right,key);
    }
}
struct Node* createNode(int Data){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->Data=Data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int main(){
    struct Node* p=createNode(50);
    struct Node* p1=createNode(40);
    struct Node* p2=createNode(20);
    struct Node* p3=createNode(45);
    struct Node* p4=createNode(60);
    struct Node* p5=createNode(55);
    struct Node* p6=createNode(70);
    p->left=p1;
    p->right=p4;
    p1->left=p2;
    p1->right=p3;
    p4->left=p5;
    p4->right=p6;
    struct Node* p7=BinarySearchTree(p,55);
    int p8=isBST(p);
      if (p8) {
        printf("THE TREE IS BST \n ");
    } else {
        printf("THE TREE IS NOT BST");
    }
      if (p7 != NULL) {
        printf("THE ELEMENT IS THERE WHICH IS %d\n", p7->Data);
    } else {
        printf("THE ELEMENT IS NOT FOUND\n");
    }
    return 0;
}
