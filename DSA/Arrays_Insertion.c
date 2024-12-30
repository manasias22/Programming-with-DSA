#include<stdio.h>
int main(){
    int arr[100]={7,8,12,24,88,108};
    int size=6,index=4,element=45;
    display(arr,size);
    insertion(arr,size,index,element,100);
    display(arr,size+1);
}
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int insertion(int arr[], int size, int index, int element, int n) {
    if(size >= n) {
        return -1;
    }
    for(int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 0;
}
