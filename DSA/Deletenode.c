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

struct Node* iOrderP(struct Node* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct Node* deleteNode(struct Node* root,int key){
    struct Node* iPre;
  // Base case.
    if (root == NULL)
    {
        return NULL;
    }

    // Searching for the node to be deleted.
    if (root->Data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->Data < key)
    {
        root->right = deleteNode(root->right, key);
    }
    // Deleting the found node.
    else
    {
        // Case 1: No child. Leaf node found.
        if (root->left == NULL && root->right == NULL && root->Data==key)
        {
            free(root);
            root = NULL;
        }
        // Case 2: 1 child.
        else if (root->left == NULL)
        {
            struct Node *ptr = root;
            root = root->right;
            free(ptr);
        }
        else if (root->right == NULL)
        {
            struct Node *ptr = root;
            root = root->left;
            free(ptr);
        }
        // Case 3: 2 children.
        else
        {
            iPre = iOrderP(root);
            root->Data = iPre->Data;
            root->left = deleteNode(root->left, iPre->Data); // deleting the duplicate from the left subtree.
        }
    }
    return root;
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
    PreOrder(p);
    deleteNode(p,10);
    printf("\n");
    PreOrder(p);
    return 0;
}
