#include<iostream>
using namespace std;
/* the goal of the algorithm:given an array of both positive and negetive numbers
and a specific starting and end points, find the maximum interval A[a..b]
the idea is still divide and conquer
we split the array into two equal sized subarrays, and find the maximum of the both the subarrays which are c1,c2 accordingly
and the one crossing the subarrays c3, and the maximum among the c1,c2,c3 is the maximum interval.
while c1,c2 can be found by recursively call the function Maximum, we only need to deal with the one crossing the 
subarrays. this can be done by linearly scanning the left and right subarrays, so for each iteration the running time 
is n; T(n)=2T(n/2)+n, running time is nlogn,
this however can be improved by revisualizing the problem

*/
int Maximumbetween(int*,int,int,int);
int Maximum(int A[],int p,int q){
    if(p==q){
        if(A[p]>0)return A[p];// 
        else return 0;
    }
    int r=(p+q)/2;
    int c1=Maximum(A,p,r);
    int c2=Maximum(A,r+1,q);
    int c3=Maximumbetween(A,p,q,r);
    if(c1>=c2&&c1>=c3)return c1;        //return the maximum of c1,c2,c3
    else if(c2>=c1&&c2>=c3)return c2;
    else return c3;
}
int Maximumbetween(int A[],int p,int q,int r){
    int Lmax,L,Rmax,R;
    Lmax=0;L=0;Rmax=0;R=0;
    for(int i=r;i>=p;i--){
        L+=A[i];
        if(L>Lmax)Lmax=L;               //linearly scan the left array
    }
    for(int i=r+1;i<=q;i++){
        R+=A[i];
        if(R>Rmax)Rmax=R;               //linearly scan the right array
    }
    return Rmax+Lmax;
}
/////////////////////now we provide the method which can solve this question in linear time//////////////////////
/*Define: 𝑋[𝑖] = 𝐴[1] + ⋯ + 𝐴[i]
X[0]=0
V[i,j]=A[i]+...+A[j]=X[j]-X[i]
For fixed j, finding largest 𝑉[𝑖,𝑗] is same as knowing the index 𝑖, 𝑖 ≤ 𝑗 for which 𝑋[𝑖 − 1] is smallest
find this for each j, let us find overall largestV[i,j]
*/
int LinearMax(int A[],int p,int q){
    int Vmax=-100000000;int Xmin=0;int X=0;
    for(int i=0;i<=q-p;i++){
        X=X+A[i];
        if(Xmin>X){Xmin=X;}
        if(Vmax<X-Xmin){Vmax=X-Xmin;}
    }
    return Vmax;
}
int main(){
    int A[9]={3,2,1,-7,5,2,-1,3,-1};
    cout<<Maximum(A,0,8)<<endl;
    cout<<LinearMax(A,0,9);
}