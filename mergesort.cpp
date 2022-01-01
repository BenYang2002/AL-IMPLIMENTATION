#include<iostream>
using namespace std;
void merge(int A[],int p,int r,int q){
    int L[r-p+2];
    int R[q-r+1];//q-(r+1)+1+1
    for(int i=0;i<r-p+1;i++){
        L[i]=A[p+i];
    }
    for(int i=0;i<q-r;i++){
        R[i]=A[r+1+i];
    }
    int i=0;int j=0;
    L[r-p+1]=10000000;
    R[q-r]=10000000;// insert "infinite at the end of each array"
    for(int x=p;x<=q;x++){
        if(L[i]<=R[j]&&L[i]!=10000000){A[x]=L[i];i++;}
        else if(L[i]>R[j]&&R[j]!=10000000){A[x]=R[j];j++;}
    }
 
}
void mergesort(int A[], int p, int q){
    if(p==q){return;}
    int r=(p+q)/2;
    mergesort(A,p,r);
    mergesort(A,r+1,q);
    merge(A,p,r,q);
};
