#include<iostream>
using namespace std;
int t0=0xAAAAAAAA;
int t1=0x12345678;
int t2;

int main(){
  t2=t0<<44;
  cout<<t2<<endl;
  t2=(t1|t2);
  cout<<t2<<endl;
}
