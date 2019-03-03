#include<iostream>
#include<vector>
using namespace std;
#define Infinity 2147483647

int num_of_tmp_array;



void print(vector<int> &A){
  for(int i=0;i<A.size();i++) cout<<A[i]<<" ";
  cout<<endl;
}


void merge(vector<int> &A,int front,int mid,int end){
  num_of_tmp_array+=2;
  vector<int> leftsub,rightsub;
  for(int i=front;i<=mid;i++) leftsub.push_back(A[i]);
  for(int i=mid+1;i<=end;i++) rightsub.push_back(A[i]);
  leftsub.push_back(Infinity);
  rightsub.push_back(Infinity);
  cout<<"leftsub=";
  print(leftsub);
  cout<<"rightsub=";
  print(rightsub);

  int index_left=0,index_right=0;
  for(int i=front;i<=end;i++){
    if(leftsub[index_left]<=rightsub[index_right]){
      A[i]=leftsub[index_left];
      index_left++;
    }else{
      A[i]=rightsub[index_right];
      index_right++;
    }
  }
}
void mergesort(vector<int> &A,int front,int end){
  if(front<end){
    int mid=(front+end)/2;
    mergesort(A,front,mid);
    mergesort(A,mid+1,end);
    merge(A,front,mid,end);
  }
}

int main(){
  vector<int> A={4,3,9,7,1,8,2,0};
  print(A);
  mergesort(A,0,A.size()-1);
  print(A);
  cout<<"num_of_tmp_array="<<num_of_tmp_array<<endl;

}
