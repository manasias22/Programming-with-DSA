#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};
void QTraversal(struct Queue* ptr) {
    int i = ptr->front;
    while (i != ptr->rear) {
        printf("ELEMENT %d\n", ptr->arr[i]);
        i = (i + 1) % ptr->size;
    }
}
int IsEmpty(struct Queue* ptr){
    if(ptr->front==ptr->rear){
        return 1;
    }
    return 0;
}
int IsFull(struct Queue* ptr){
    if((ptr->rear+1)%ptr->size==ptr->front){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue* ptr,int val){
    if(IsFull(ptr)){
        printf("QUEUE OVERFLOW \n");
    }
    ptr->rear=(ptr->rear+1)%ptr->size;
    ptr->arr[ptr->rear]=val;
    printf("ELEMENT HAS BEEN ENQUEUED %d \n",val);
}
int dequeue(struct Queue* ptr){
    if(IsEmpty(ptr)){
        printf("QUEUE UNDERFLOW \n");
        return -1;
    }
    ptr->front=(ptr->front+1)%ptr->size;
    int val=ptr->arr[ptr->front];
    return val;
}
int main(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->size=4;
    q->front=q->rear=0;
    q->arr=(int*)malloc(q->size*sizeof(int));
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    int val=dequeue(q);
     val=dequeue(q);
     printf("ELEMENT HAS BEEN DEQUEUED %d \n",val);
     enqueue(q,40);
     enqueue(q,50);
     QTraversal(q);
    return 0;
}




