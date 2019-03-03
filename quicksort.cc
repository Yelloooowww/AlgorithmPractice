#include<iostream>
using namespace std;

void swap(int *a,int *b){
  int tmp= *a;
  *a= *b;
  *b=tmp;
}

void print(int *a,int N){
  for(int i=0;i<N;i++) cout<<a[i]<<" ";
  cout<<endl;
}
int partition(int *a,int front,int end){
  int pivot=a[end],i=front-1,j;
  for(j=front;j<end;j++){
    if(a[j]<pivot){
      i++;
      swap(a[i],a[j]);
    }
  }
  i++;
  swap(&a[i],&a[j]);
  return i;

}
void quicksort(int *a,int front,int end){
  if(front<end){
    int pivot=partition(a,front,end);
    quicksort(a,front,pivot-1);
    quicksort(a,pivot+1,end);
  }
}



int main(){
  int A[]={2,6,4,1,7,1,8,6,9,4,3,0,8,6};
  print(A,sizeof(A)/4);
  quicksort(A,0,sizeof(A)/4 -1);
  print(A,sizeof(A)/4);

}
