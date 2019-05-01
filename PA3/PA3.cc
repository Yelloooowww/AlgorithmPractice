#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct job{
  int id;
  int time;
  int deadline;
};


void SortByTime(job S[],int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N-i;j++){
      if((S[j]).time>(S[j+1]).time){
        job tmp=S[j];
        S[j]=S[j+1];
        S[j+1]=tmp;
      }
    }
  }
}

bool IsFeasibleSet(job K[],int N){
  if(N==1) return 1;

  for(int i=N-1;i>0;i--){
    if((K[i]).deadline<(K[i-1]).deadline){
      job tmp=K[i];
      K[i]=K[i-1];
      K[i-1]=tmp;
    }
  }

  int tmp=0;
  for(int i=0;i<N;i++) tmp += K[i].time;
  return ((tmp<=K[N-1].deadline)?1:0);

}


int schedule(job S[],int N){
  int total_time=0;
  int num=0;
  job J[N];
  job K[N];

  for(int i=0;i<N;i++){
    K[num]=S[i];

    if( IsFeasibleSet(K,num+1)){
      num++;
      for(int i=0;i<num;i++) J[i]=K[i];
    }else{
      for(int i=0;i<num;i++) K[i]=J[i];
    }
  }


  return num;
}

int main(){
  while(1){
    int N;
    cout<<"Input:"<<endl;
    cin>>N;
    job S[N];
    for(int i=0;i<N;i++){
      int tmp1,tmp2;
      cin>>tmp1>>tmp2;
      (S[i]).id=i+1;
      (S[i]).time=tmp1;
      (S[i]).deadline=tmp2;
    }

    SortByTime(S,N);
    int MaxProfit=schedule(S,N);
    cout<<"Maximum Profit="<<MaxProfit<<endl;
  }
}
