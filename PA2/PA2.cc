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
  //only accept +-*
  assert(op=='+' ||op=='-' || op=='*');
  switch (op) {
    case '+': return n1+n2;
    case '-': return n1-n2;
    case '*': return n1*n2;
  }
}

string int_to_string(int n){
  string s="";
  while(n){
    s.insert(s.begin(),n%10+48);
    n=n/10;
  }
  return s;
}

void Ans(int *p,int *k,int size,int start,int end){
  if(end==start){
    cout<<int_to_string( *(p+start*(size+1)+end) );
    return;
  }else{
    char flag=0;// 0->()   1->no()
    int divide= *(k+start*(size+1)+end);

    //some case which don't need ()
    if(start==1 && end==size) {
      flag=1;
    }else if(Operator[divide]=='*' ){
      flag=1;
    }else if(Operator[divide]=='+' || Operator[divide]=='-'){
      if(Operator[divide+1]!='*' && Operator[divide-1]!='*') flag=1;
    }

    if(flag==0) cout<<"(";
    Ans(p,k,size,start,divide);
    cout<<Operator[divide];
    Ans(p,k,size,divide+1,end);
    if(flag==0) cout<<")";
  }

}


void MaxCalculation(int *Number,char *Op,int size){
  int p[size+1][size+1];//the result of each fractional calculation
  int k[size+1][size+1];//divide method
  int Num[size+1];//there are n integer,n=size.
  char Operator[size];//there are n operator,n=size-1.

  //copy data for the using in this fuction
  for(int i=0;i<=size;i++) Num[i]= *(Number+i);
  for(int i=0;i<=size-1;i++) Operator[i]= *(Op+i);




  for(int i=1;i<=size;i++) p[i][i]=Num[i];//initial p[][] when i==j

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
  cout<<endl<<"p:"<<endl;
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

  Ans(&p[0][0],&k[0][0],size,1,size);
  cout<<"="<<p[1][size]<<endl;
}

int main(){

  while(1){
    Num.clear();
    Operator.clear();
    cout<<"input"<<endl;
    cin>>input;

    deal_with_input();//analysis what user input ans put them into data structure
    MaxCalculation(&(Num[0]),&(Operator[0]),Num.size()-1);//a DP algorithm




  }
  return 0;
}
