#include<stdio.h>
void Display(int A[],int n){
    for(int i=0;i<n;i++){
        printf(" %d  ",A[i]);
    }
    printf(" \n ");
}
int Partition(int A[],int Low,int High){
    int Pivot=A[Low];
    int i=Low+1;
    int j=High;
    int temp;
    do{
        while(Pivot>=A[i] && i <= High){
            i++;
        }
        while(Pivot<A[j] && j>=Low){
            j--;
        }
        if(i<j){
           temp= A[i];
           A[i]=A[j];
           A[j]=temp;
        }
    }while(i<j);
    temp=A[Low];
    A[Low]=A[j];
    A[j]=temp;
    return j;
}



void QuickSort(int A[],int Low,int High){
    if(Low<High){
        int Pi=Partition(A,Low,High);
        QuickSort(A,Low,Pi-1);
        QuickSort(A,Pi+1,High);
    }
}
int main(){
    int A[]={2,34,232,221,233,3,22,1,21,23,0};
    int n=sizeof(A)/sizeof(int);
    Display(A,n);
    QuickSort(A,0,n-1);
    Display(A,n);
    return 0;
}

//TIME COMPLEXITY O(n2)
// BEST CASE O(nlogn)



