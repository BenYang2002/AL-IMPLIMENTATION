#include<iostream>
using namespace std;
/*count inversions of an array we can use divide and conquer:
we count the inversions on the left subarray and the right subarray and the 
inversions in between.
when counting the inversions in bertween we first assume that the left and right arrays are sorted
similar to merge sort we have two pointer which will go through the left and right array
and if the ith number pointed by the left array pointer is smaller than the jth number pointed by
the right array, and assume the array A starts from p and ends at q and r=(p+q)/2, the number of inversions caused by
i will be r-p+1-i+1=r-p-i+2*/
int merge_and_count(int*,int,int);
int sort_and_count(int A[],int p,int q){
    if(p==q){return 0;}
    int r=(p+q)/2;
    int c1,c2,c3;
    c1=sort_and_count(A,p,r);
    c2=sort_and_count(A,r+1,q);
    c3=merge_and_count(A,p,q);
    return c1+c2+c3;// 3 step: count the inversions on the left array, right array and inversion in between
};
int merge_and_count(int A[],int p,int q){
    int r=(p+q)/2;
    int L[r-p+2];
    int R[q-r+1];
    L[r-p+1]=100000000;
    R[q-r]=100000000;// insert infinity at the end of each array
    for(int i=0;i<r-p+1;i++){L[i]=A[p+i];}
    for(int i=0;i<q-r;i++){R[i]=A[r+1+i];}
    int l=0;int r1=0;int number=0;
    for(int i=0;i<q-p+1;i++){
        if(L[l]<=R[r1]){A[i]=L[l];l++;}
        if(L[l]>R[r1]&&L[l]!=100000000){A[i]=R[r1];number+=r-p-l+2;r1++;}// we add the number if number on the left is larger than the right since only then will the inversion appears
        else if(L[l]>R[r1]&&L[l]==100000000){A[i]=R[r1];r1++;}// handle the special case when the left reaches the end(the infinity) we don't add the number cuz infinity doesn't count
    }
    return number;

};
int main(){
    int A[12]={1,5,4,8,10,2,6,9,12,11,3,7};
    cout<<sort_and_count(A,0,9);
}