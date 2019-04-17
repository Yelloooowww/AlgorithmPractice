#include<iostream>
#include<string>
#include<vector>
#include<cassert>
#include<iomanip>
#define NegativeInfinite -2147483647
using namespace std;

string input;
vector<int> Num;
vector<char> Operator;

void deal_with_input(){
  //we don't use Num[0] & Operator[0],just filled it .
  Num.push_back(NegativeInfinite);
  Operator.push_back('N');

  //analysis what user input
  //put unsiged int ---->  vector<int> Num;
  //put +-*/        ---->  vector<char> Operator;
  int accumulation=0;
  for(int i=0;i<input.size();i++){
    if(input[i]>=48 && input[i]<=57){
      //integer num
      accumulation*=10;
      accumulation+=(input[i]-48);
    }else{
      //operator
      Num.push_back(accumulation);
      accumulation=0;
      Operator.push_back(input[i]);
    }
  }
  Num.push_back(accumulation);
}

int calculation(int n1,char op,int n2){
  assert(op=='+' ||op=='-' || op=='*'|| op=='/');
  switch (op) {
    case '+': return n1+n2;
    case '-': return n1-n2;
    case '*': return n1*n2;
    case '/': return n1/n2;
  }
}



int MaxCalculation(int *Number,char *Op,int size){
  int p[size+1][size+1];//the result of each calculation
  int k[size+1][size+1];//divide method
  int Num[size+1];//there are n integer,n=size.
  char Operator[size];//there are n operator,n=size-1.

  //copy data for the using in this fuction
  for(int i=0;i<=size;i++) Num[i]= *(Number+i);
  for(int i=0;i<=size-1;i++) Operator[i]= *(Op+i);




  for(int i=1;i<=size;i++) p[i][i]=Num[i];//init p[][] when i==j

  for(int line=1;line<=size-1;line++){
    int i=1;
    int j=i+line;
    //make diagonal
    while(i<=size && j<=size){
      int max=NegativeInfinite;
      int max_index;

      //find max
      for(int l=i;l<=j-1;l++){
        int tmp=calculation(p[i][l],Operator[l],p[l+1][j]);
        if(tmp>max){
          max=tmp;
          max_index=l;
        }
      }
      p[i][j]=max;
      k[i][j]=max_index;
      i++;
      j++;
    }
  }


  //print Ans~~~~~~~~~~~~~~~~~~~~~~~
  cout<<"p:"<<endl;
  for(int i=1;i<=size;i++){
    for(int j=1;j<=size;j++){
      if(j>=i) cout<<setw(5)<<p[i][j];
      else cout<<setw(5)<<'-';
    }
    cout<<endl;
  }
  cout<<"k:"<<endl;
  for(int i=1;i<=size;i++){
    for(int j=1;j<=size;j++){
      if(j>i) cout<<setw(5)<<k[i][j];
      else cout<<setw(5)<<'-';
    }
    cout<<endl;
  }
}

int main(){

  while(1){
    Num.clear();
    Operator.clear();
    cout<<"input"<<endl;
    cin>>input;

    deal_with_input();//put into data structure
    MaxCalculation(&(Num[0]),&(Operator[0]),Num.size()-1);




  }





  return 0;
}
