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
        printf("  %d   ",root->Data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InsertNode(struct Node* root,int key){
    struct Node* prev=NULL;
    while(root!=NULL){
        prev=root;
        if(root->Data==key){
            return;
        }
        else if(root->Data<key){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    struct Node* n=createNode(key);
    if(prev->Data>key){
        prev->left=n;
    }
    else{
        prev->right=n;
    }
}

struct Node* inOrderP(struct Node* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct Node* DeleteNode(struct Node* root,int key){
    struct Node* iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->Data>key){
        root->left=DeleteNode(root->left,key);
    }
    else if(root->Data<key){
        root->right=DeleteNode(root->right,key);
    }
    else{
        // no child
        if(root->Data==key && root->right==NULL && root->left==NULL){
            free(root);
            return NULL;
        } // 1 child
        else if(root->left==NULL){
            struct Node* ptr=root->right;
            free(root);
            return ptr;
        }
        else if(root->right==NULL){
            struct Node* ptr=root->left;
            free(ptr);
            return ptr;
        }
        else{
            iPre=inOrderP(root);
            root->Data=iPre->Data;
            root->left=DeleteNode(root->left,iPre->Data);
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
    //InsertNode(p,9);
    p=DeleteNode(p,10);
    printf("\n");
    PreOrder(p);
    return 0;
}
