#include<stdio.h>
int main(){
    int arr[]={1239,231,3139,311,4229,442,452,644,4224};
    int size=sizeof(arr)/sizeof(int);
    int element=452,index;
    sorting(arr,size);
    index= binarysearch(arr,size,element,0);
    printf("postion: %d",index);
    return 0;
}
int binarysearch(int arr[],int high,int element,int low){
    int mid=(low+high)/2;
    if(arr[mid]==element){
        return mid;
    }
    if(arr[mid]<element){
        return binarysearch(arr,high,element,mid);
    }
    if(arr[mid>element]){
        return binarysearch(arr,mid,element,low);
    }
    return -1;
}
void sorting(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
