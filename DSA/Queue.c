#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rearer;
    int *arr;
};
void QTraversal(struct Queue* ptr) {
    int i;
    for (i = ptr->front + 1; i <= ptr->rearer; i++) {
        printf("%d  \n", ptr->arr[i]);
    }
}
int IsEmpty(struct Queue* ptr){
    if(ptr->front==ptr->rearer){
        return 1;
    }
    return 0;
}
int IsFull(struct Queue* ptr){
    if(ptr->rearer==ptr->size-1){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue* ptr,int val){
    if(IsFull(ptr)){
        printf("QUEUE OVERFLOW \n");
    }
    ptr->rearer++;
    ptr->arr[ptr->rearer]=val;
}
int dequeue(struct Queue* ptr){
    if(IsEmpty(ptr)){
        printf("QUEUE UNDERFLOW \n");
        return -1;
    }
    ptr->front++;
    int val=ptr->arr[ptr->front];
    return val;
}
int main(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->size=10;
    q->front=-1;
    q->rearer=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);
    enqueue(q,70);
    enqueue(q,80);
    enqueue(q,90);
    enqueue(q,100);
    //int val=dequeue(q);
    //printf("THE ELEMENT DEQUEUE IS %d  \n",val);
    QTraversal(q);
    return 0;
}
