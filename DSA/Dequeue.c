#include<stdio.h>
#include<stdlib.h>
struct Dequeue{
    int size;
    int front;
    int rear;
    int *arr;
};
int IsEmpty(struct Dequeue* ptr){
    if(ptr->rear==ptr->front){
        return 1;
    }
    return 0;
}
int IsFull(struct Dequeue* ptr){
    if(ptr->rear==ptr->size-1){
        return 1;
    }
    return 0;
}
//insertion at ending
void InsertionR(struct Dequeue* ptr,int val){
    if(IsFull(ptr)){
        printf("QUEUE IS FULL \n");
    }
    ptr->rear++;
    ptr->arr[ptr->rear]=val;
    printf("Successfully inserted the elemet at the rear\n");
}
//insertion at starting
void InsertionS(struct Dequeue* ptr,int val){
    if(IsFull(ptr) || ptr->front==-1){
        printf("QUEUE OPERATION CANNOT BE TAKEN PLACE \n");
    }
    else{
    ptr->arr[ptr->front]=val;
    ptr->front--;
    printf("Successfullly inserted the element at the front\n"); 
    }
}
int DeletionF(struct Dequeue* ptr){
    if(IsEmpty(ptr)){
        printf("There is no elemet in the Queue\n");
        return -1;
    }
    else{
        ptr->front++;
        int val=ptr->arr[ptr->front];
        ptr->front++;
        return val;
    }
}
int DeletionR(struct Dequeue* ptr){
    if(IsEmpty(ptr)){
        printf("There is no elemet in the Queue\n");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->rear];
        ptr->rear--;
        return val;
    }
}


// Displaying the DEQueue element
void Display(struct Dequeue * q)
{
    int i=0;
    while(i<=(q->rear))
    {
        printf("Element:%d\n",q->arr[i]);
        i++;
    }
}
int main(){
    struct Dequeue* d=(struct Dequeue*)malloc(sizeof(struct Dequeue));
    d->size=4;
    d->front=d->rear=-1;
    d->arr=(int*)malloc(d->size*sizeof(int));
    InsertionR(d,10);
    InsertionR(d,20);
    InsertionR(d,30);
    InsertionR(d,40);
    InsertionR(d,50);
    Display(d);
    DeletionF(d);
    Display(d);
    DeletionR(d);
    Display(d);
    
    
    return 0;
}
