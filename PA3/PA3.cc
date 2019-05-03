#include<iostream>
#include<queue>
using namespace std;

class job{
private:
  int time;
  int deadline;
public:
  job(int t,int d):time(t),deadline(d){}
  int get_time(){return time;}
  int get_deadline(){return deadline;}
  friend bool operator> (const job& a, const job& b){
    return a.deadline > b.deadline;
  }
  friend bool operator< (const job& a, const job& b){
    return a.time < b.time;
  }
  friend ostream& operator<< (ostream& out,const job& foo){
    return out<<"time("<<foo.time<<")deadline("<<foo.deadline<<")";
  }
};

class schedule{
private:
  priority_queue<job> J;
  int total_time;
public:
  schedule(int t=0):total_time(t){}
  void add_job(job foo){
    J.push(foo);
    total_time+= foo.get_time();
    if(total_time> foo.get_deadline()){
      job tmp=J.top();
      total_time -=tmp.get_time();
      J.pop();
    }
  }
  int get_num(){return J.size();}
};

int main(){
  while(1){
    int N;
    cout<<"Input:"<<endl;
    cin>>N;

    priority_queue< job,deque<job>,greater<job> > S;
    for(int i=0;i<N;i++){
      int tmp1,tmp2;
      cin>>tmp1>>tmp2;
      S.push(job(tmp1,tmp2));
    }

    schedule MaxProfit;
    while (!S.empty()) {
      MaxProfit.add_job(S.top());
      S.pop();
    }
    cout<<"Maximum Profix="<<MaxProfit.get_num()<<endl;
  }
}
