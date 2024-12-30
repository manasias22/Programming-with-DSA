// Online C compiler to run C program online
#include <stdio.h>
void Display(int *A,int n){
    for(int i=0;i<n;i++){
        printf(" %d  ",A[i]);
    }
    printf(" \n ");
}
void SelectionSort(int *A,int n){
    int minindex,temp;
    for(int i=0;i<n-1;i++){
        minindex=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[minindex]){
                minindex=j;
            }
        }
            temp=A[i];
            A[i]=A[minindex];
            A[minindex]=temp;
    }
}
int main(){
    int A[]={12,54,65,7,23,9};
    int n=sizeof(A)/sizeof(int);
    Display(A,n);
    SelectionSort(A,n);
    Display(A,n);
    return 0;
}
