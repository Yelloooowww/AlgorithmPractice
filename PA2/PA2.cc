#include<iostream>
#include<string>
#include<vector>
using namespace std;

string input;
vector<int> Num;
vector<char> Operator;

void deal_with_input(){
  int accumulation;
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

int main(){

  while(1){
    Num.clear();
    Operator.clear();
    cout<<"input"<<endl;
    cin>>input;

    deal_with_input();

    
  }





  return 0;
}
