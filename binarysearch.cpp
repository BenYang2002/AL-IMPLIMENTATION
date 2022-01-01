#include<iostream>
#include"mergesort.cpp"
using namespace std;
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
    }// handling input
    
    for(int i=0;i<size;i++){
        cout<<input[i]<<"\t";
    }
    cout<<endl;
    cout<<"what's the number that you want?";
    int wantednum;
    cin>>wantednum;
    mergesort(input,0,size-1);
    if(binarysearch(input,0,size-1,wantednum)){cout<<"the number is found";}
    else{cout<< "number is not found";}
}