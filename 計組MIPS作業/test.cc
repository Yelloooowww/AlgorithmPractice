#include<iostream>
using namespace std;

int test(int n){
  int tmp=2;
  while(tmp<n){
    if (n%tmp==0) return 1;
    tmp ++;
  }
  return 0;
}

int main(){

  while (1) {
    cout<<"INPUT:"<<endl;
    int n;
    cin>>n;

    int ans=test( n);
    if(ans) cout<<"Not"<<endl;
    else cout<<"yes"<<endl;
  }






  return 0;
}
