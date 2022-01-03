#include<iostream>
using namespace std;
//running time:
// the running time of the merge sort is nlogn

// intuition:
//mergesort has two processes: mergesort the subproblem and merge
//mergesort the subproblem will first sort the subarrays and merge will 
// merge the subarrays into a sorted whole array.

//detail:
//mergesort the subproblem:
//we divide the problem into smaller pieces, and recursively call the mergesort
//the base case is when the subproblem only has one element
//merge:
//we create two arrays L array and R array to contain the elements in the left and right subproblems
//at this point, the subproblems are already sorted, now imagine there are two pointers l and r pointing at the start
//of the L and R array accordingly,and insert a infinite large number at the end of each array.
//just to illustrate, we create another array F to contain the final result, but actually we just put the 
// sorted elements back to the original array 
//now we compare the numbers the l and r are pointing at
//if the the l number is smaller than r number, we put the l number into the first place of F
//and move the l pointer to the next element of L
//vice versa
//continue this process until there's no more element to compare


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
