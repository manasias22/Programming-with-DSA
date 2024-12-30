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

void printTree(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->Data);
        printTree(root->left);
        printTree(root->right);
    }
}
int main(){
    struct Node* p=createNode(2);
    struct Node* p1=createNode(4);
    struct Node* p2=createNode(6);
    p->left=p1;
    p->right=p2;
    printf("Tree structure: \n ");
    printTree(p);
    return 0;
}
