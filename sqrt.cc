#include<iostream>
using namespace std;

int sqrt(int n){
  int i=1;
  while(i++){
    // cout<<"i="<<i<<endl;
    if(i*i >n) break;
  }
  return i-1;
}

int min(int *x,int m,int *y,int n){
  if(x[m-1]<y[0]) return y[0]-x[m-1];
  if(y[n-1]<x[0]) return x[0]-y[n-1];

  char flag=0;
  int min=abs(x[m-1]-y[0]);
  for(int i=m-1;i>=0;i--){
    for(int j=0;j<n;j++){
      cout<<"i="<<i<<" j="<<j<<" abs="<<abs(x[i]-y[j]);
      if(abs(x[i]-y[j])<min){
        min=abs(x[i]-y[j]);
        cout<<"V";
        flag=1;
      }
      else if(flag==1) return min;

      cout<<endl;
    }
  }
  return min;
}

int main(){
  int A[5]={2,4,6,8,10};
  int B[7]={0,1,3,5,7,9,11};
  int ans=min(A,5,B,7);
  cout<<"ans="<<ans<<endl;

  cout<<"input a num:";
  int n;
  cin>>n;
  cout<<"sqrt("<<n<<")="<<sqrt(n)<<endl;


}
