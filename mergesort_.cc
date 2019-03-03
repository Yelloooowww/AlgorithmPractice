#include<iostream>
using namespace std;
#define Infinity 2147483647


int A[]={7,0,2,6,8,4,12,9};
#define N sizeof(A)/4
int tmp[N/2];//extra space



void merge(int *A,int front,int mid,int end){
  int index_left=front,index_right=mid+1,index_tmp=front;

  while(index_left<=mid && index_right<=end){
    if(A[index_left]<=A[index_right]){
      if(index_tmp<mid+1){
        tmp[index_tmp]=A[index_left];//using extra space
      }else{
        A[index_tmp]=A[index_left];//using itself
      }
      index_tmp++;
      index_left++;
    }else{
      if(index_tmp<mid+1){
        tmp[index_tmp]=A[index_right];//using extra space
      }else{
        A[index_tmp]=A[index_right];//using itself
      }
      index_tmp++;
      index_right++;
    }
  }


  while(index_left<=mid){
    A[index_tmp]=A[index_left];
    index_tmp++;
    index_left++;
  }

  //copy extra space to itself
  for(int i=front;i<mid+1;i++) A[i]=tmp[i];


  //print ans~~~
  cout<<"merge:";
  for(int i=front;i<end+1;i++) cout<<A[i]<<" ";
  cout<<endl;
}


void mergesort(int *A,int front,int end){
  if(front<end){
    int mid=(front+end)/2;
    mergesort(A,front,mid);
    mergesort(A,mid+1,end);
    merge(A,front,mid,end);
  }
}



int main(){
  cout<<"input:";
  for(int i=0;i<N;i++) cout<<A[i]<<" ";
  cout<<endl;


  mergesort(A,0,N-1);
}
