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
void PostOrder(struct Node* root){
    if(root!=NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf(" %d  ",root->Data);
    }
}
int main(){
    struct Node* p= createNode(4);
    struct Node* p1=createNode(1);
    struct Node* p2=createNode(6);
    struct Node* p3=createNode(5);
    struct Node* p4=createNode(2);
    //  4
    // 1  6
//  5   2    
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    PostOrder(p);
    return 0;
}
