#include<iostream>
using namespace std;

void print(int *a,int N){
  for(int i=0;i<N;i++) cout<<a[i]<<" ";
  cout<<endl;
}

void HW1Q7(int *a,int N){
  int index=1;
  while (index<N) {
    if(index==0 || a[index]>=a[index-1]){
      index++;
    }else{
      int tmp=a[index];
      a[index]=a[index-1];
      a[index-1]=tmp;

      index--;
    }
  }
}
int main(){
  int N=13;
  int A[N]={81,94,11,96,12,35,17,95,28,58,41,75,15};
  int B[N]={81,94,11,96,12,35,17,95,28,58,41,75,15};
  int C[N]={81,94,11,96,12,35,17,95,28,58,41,75,15};
  int D[N]={81,94,11,96,12,35,17,95,28,58,41,75,15};
  int E[N]={81,94,11,96,12,35,17,95,28,58,41,75,15};

  //insert
  for(int i=1;i<N;i++){
    for(int j=i;j>0;j--){
      if(A[j]<A[j-1]){
        int tmp=A[j];
        A[j]=A[j-1];
        A[j-1]=tmp;
      }
    }
  }
  //shellsort
  for(int gap=N/2;gap>0;gap/=2){
    for(int i=gap;i<N;i+=gap){
      for(int j=i;j>0;j-=gap){
        if(B[j]<B[j-gap]){
          cout<<"exchange"<<B[j]<<"<->"<<B[j-gap]<<endl;
          int tmp=B[j];
          B[j]=B[j-gap];
          B[j-gap]=tmp;
        }
      }
    }
  }

  //selection sort
  for(int i=0;i<N;i++){
    int min_index=i;
    for(int j=min_index+1;j<N;j++){
      if(C[j]<C[min_index]){
        min_index=j;
      }
    }
    if(min_index!=i){
      int tmp=C[min_index];
      C[min_index]=C[i];
      C[i]=tmp;
    }
  }

  //bubble sort
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(D[j]<D[i]){
        int tmp=D[j];
        D[j]=D[i];
        D[i]=tmp;
      }
    }
  }



  cout<<"A=";
  print(A,N);

  cout<<"B=";
  print(B,N);

  cout<<"C=";
  print(C,N);

  cout<<"D=";
  print(D,N);

  HW1Q7(E,N);
  cout<<"E=";
  print(E,N);


  return 0;
}
