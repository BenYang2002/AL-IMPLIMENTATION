#include<iostream>
#include"mergesort.cpp"
using namespace std;
/*binary search's idea is:
when have an array of numbers say 5,3,6,1
first sort the array(here I use mergesort whose running time is nlogn) 
since we need the property of sorted array, now the array is 1,3,5,6
Then we compare the target number t with the median m
if t >= m , we now do the binary search on the number including and after m (ie. 5,6)
otherwise the number before m(ie. 1,3)
*/ 
bool binarysearch(int A[],int p,int q,int num){
    if(p==q&&A[p]==num){return true;}
    else if(p==q&&A[p]!=num){return false;}
    int r=(p+q)/2;
    if(A[r]>=num){return binarysearch(A,p,r,num);}
    if(A[r]<num){return binarysearch(A,r+1,q,num);}
};


int main(){
    int size=0;
    int* input;
    int number;
    cout<<"input the numbers,enter -1 to finish inputing"<<endl;
    while(true)
    {   cin>>number;
        if(number==-1){break;}
        size++;
        int* newinput= new int[size];
        
        if(size!=1){
            for(int i=0;i<size-1;i++){
                newinput[i]=input[i];
            }
            newinput[size-1]=number;
            delete[] input;
            input=newinput;  
                   }
        else{input= new int[1];
            input[0]=number;}
    }
    /////////////////////////// handling input///////////////////////////////
    
    for(int i=0;i<size;i++){
        cout<<input[i]<<"\t";
    }
    cout<<endl;
    cout<<"what's the number that you want?";
    int wantednum;
    cin>>wantednum;
    mergesort(input,0,size-1);// sort the array 
    if(binarysearch(input,0,size-1,wantednum)){cout<<"the number is found";}
    else{cout<< "number is not found";}
}
// First you have to manually input the numbers
//input -1 to finish inputing
// and then input the number you want to search.