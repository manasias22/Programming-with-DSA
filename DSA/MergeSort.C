#include<stdio.h>
void Display(int A[],int n){
    for(int i=0;i<n;i++){
        printf(" %d  ",A[i]);
    }
    printf(" \n ");
}
void Merge(int A[],int Low,int Mid,int High){
    int i,j,k;
    int n1=Mid+1-Low;
    int n2=High-Mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
    L[i]=A[Low+i];
    for(int j=0;j<n2;j++)
    R[j]=A[Mid+1+j];
    i=0;
    j=0;
    k=Low;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
            k++;
        }
        else{
            A[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }
}




void MergeSort(int A[],int Low,int High){
    int mid;
    if(Low<High){
        mid=Low+(High-Low)/2;
        MergeSort(A,Low,mid);
        MergeSort(A,mid+1,High);
        Merge(A,Low,mid,High);
    }
}
int main(){
    int A[]={2,34,232,221,233,3,22,1,21,23,0};
    int n=sizeof(A)/sizeof(int);
    Display(A,n);
    MergeSort(A,0,n-1);
    Display(A,n);
    return 0;
}

//TIME COMPLEXITY O(n2)
// BEST CASE O(nlogn)



