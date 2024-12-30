#include<stdio.h>
int main(){
    int arr[]={23,4,5,6,3,2,1,0,5678};
    int size=sizeof(arr)/sizeof(int);
    int element=3,index;
    index= linearsearch90(arr,size,element);
    printf("the element is at place number %d",index);
    return 0;
}
int linearsearch90(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
