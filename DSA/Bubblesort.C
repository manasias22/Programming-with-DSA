#include<stdio.h>
void Display(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d  ",A[i]);
    }
    printf(" \n ");
}
void BubbleSort(int *A,int n){
    int temp,isSorted;
    for(int i=0; i<n-1;i++){
        printf("AT EACH PASS %d  \n",i);
        isSorted=1;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSorted=0;
            }
        }
        if(isSorted){
            return;
        }
    }
}
int main(){
    int A[]={232,223,334,21,22,11,21,31};
    int n=sizeof(A)/sizeof(int);
    Display(A,n);
    BubbleSort(A,n);
    Display(A,n);
}
//Timecomplexity O(n2) SpaceComplexity O(n2)
