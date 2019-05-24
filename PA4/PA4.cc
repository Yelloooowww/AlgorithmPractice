#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<ctime>
using namespace std;
#define Infinite 99999

typedef int vertex;
struct edge{
  vertex from;
  vertex to;
  int weight;
  edge(int f,int t,int w):from(f),to(t),weight(w){};
};
struct graph{
  int V;//num of vertex,
  int E;//num of edge
  vector<edge> Edges;//set of edge
  vector<vertex> d;//record the shortest weight from sourse
  vector<vertex> pi;//record the last vertex
  bool ExistNegativeCycle;//1->exist  0->doesn't exist
  stack<vertex> AnsPath;//the shortest path or the negative cycle
  int AnsWeight;
  graph(int v=0,int e=0):V(v),E(e){};
  void clearAns(){
    ExistNegativeCycle= -1;
    AnsWeight=0;
    while(!AnsPath.empty()) AnsPath.pop();
  }
  void PrintAns(){
    if(!(ExistNegativeCycle==1 || ExistNegativeCycle==0)) cout<<"ERROR"<<endl;
    if(ExistNegativeCycle==1) cout<<"There is a negative weight cycle."<<endl;

    bool haveprint[V];for(int i=0;i<V;i++) haveprint[i]=0;
    while (!AnsPath.empty()  &&(!haveprint[AnsPath.top()])){
      cout<<AnsPath.top()<<" ";
      haveprint[AnsPath.top()]=1;
      AnsPath.pop();
    }
    if(ExistNegativeCycle==0) cout<<endl<<AnsWeight<<endl;
  }
};


bool BellmanFord(graph& G,vertex& s,vertex& destination){
  //initialize
  for(int i=0;i<G.V;i++){
    G.d.push_back(Infinite);
    G.pi.push_back(-Infinite);
  }
  G.d[s]=0;
  vector< vector<int> > w;
  for(int i=0;i<G.V;i++){
    vector<int> tmp;
    for(int j=0;j<G.V;j++) {
      if(i==j) tmp.push_back(0);//w[i][j]=0;
      else tmp.push_back(Infinite);//w[i][j]=Infinite;
    }
    w.push_back(tmp);
  }
  vector<vertex> adj[G.V];
  for(int i=0;i<G.V;i++) adj[i].clear();
  for(int j=0;j<G.E;j++){
    vertex u=G.Edges[j].from;
    vertex v=G.Edges[j].to;
    w[u][v]=G.Edges[j].weight;
    adj[u].push_back(v);
  }
  G.clearAns();
  //initialize done

  //edit d & pi
  for(int i=0;i<G.V-1;i++){
    for(int j=0;j<G.E;j++){
      vertex u=G.Edges[j].from;
      vertex v=G.Edges[j].to;
      if(G.d[v]> (G.d[u]+w[u][v])){
        G.d[v]= (G.d[u]+w[u][v]);
        G.pi[v]=u;
      }
    }
  }

  //check if there exist a negative weight cycle?
  for(int j=0;j<G.E;j++){
    vertex u=G.Edges[j].from;
    vertex v=G.Edges[j].to;
    if(G.d[v]> (G.d[u]+w[u][v])){
      bool HaveFinded[G.V];for(int i=0;i<G.V;i++) HaveFinded[i]=0;
      G.AnsPath.push(v);
      HaveFinded[v]=1;
      while(HaveFinded[u]!=1){
        v=u;
        u=G.pi[v];
        G.AnsPath.push(v);
        HaveFinded[v]=1;
      }
      G.AnsPath.push(u);
      G.ExistNegativeCycle=1;
      return 0;
    }
  }

  //No negative weight cycle. Start to print the shortest path.
  vertex now=destination;
  vertex last=G.pi[now];
  while(now!=s){
    G.AnsWeight += w[last][now];
    G.AnsPath.push(now);
    now=last;
    last=G.pi[now];
  }
  G.AnsPath.push(s);
  G.ExistNegativeCycle=0;
  return 1;
}


bool modified_BellmanFord(graph& G,vertex& s,vertex& destination){
  //initialize
  for(int i=0;i<G.V;i++){
    G.d.push_back(Infinite);
    G.pi.push_back(-Infinite);
  }
  G.d[s]=0;
  vector< vector<int> > w;
  for(int i=0;i<G.V;i++){
    vector<int> tmp;
    for(int j=0;j<G.V;j++) {
      if(i==j) tmp.push_back(0);//w[i][j]=0;
      else tmp.push_back(Infinite);//w[i][j]=Infinite;
    }
    w.push_back(tmp);
  }
  vector<vertex> adj[G.V];
  for(int i=0;i<G.V;i++) adj[i].clear();
  for(int j=0;j<G.E;j++){
    vertex u=G.Edges[j].from;
    vertex v=G.Edges[j].to;
    w[u][v]=G.Edges[j].weight;
    adj[u].push_back(v);
  }
  G.clearAns();
  //initialize done

  //edit d & pi
  queue<vertex> Q;
  bool color[G.V];for(int i=0;i<G.V;i++) color[i]=0;
  //color=1 -> have been pushud into Q
  Q.push(s);
  color[s]=1;
  while (!Q.empty()) {
    vertex u=Q.front();
    Q.pop();
    for(int i=0;i<adj[u].size();i++){
      vertex v=adj[u][i];
      if(G.d[v]> (G.d[u]+w[u][v])){
        G.d[v]= (G.d[u]+w[u][v]);
        G.pi[v]=u;
      }
      if(color[v]!=1){
        Q.push(v);
        color[v]=1;
      }
    }
  }

  //check if there exist a negative weight cycle?
  queue<vertex> Q_;
  int color_[G.V];for(int i=0;i<G.V;i++) color_[i]=0;
  //1->have been pushud into Q
  Q_.push(s);
  color_[s]=1;
  while (!Q_.empty()) {
    vertex u=Q_.front();
    Q_.pop();
    for(int i=0;i<adj[u].size();i++){
      vertex v=adj[u][i];
      if(G.d[v]> (G.d[u]+w[u][v])){
        int HaveFinded[G.V];
        G.AnsPath.push(v);
        HaveFinded[v]=1;
        while(HaveFinded[u]!=1){
          v=u;
          u=G.pi[v];
          G.AnsPath.push(v);
          HaveFinded[v]=1;
        }
        G.AnsPath.push(u);
        G.ExistNegativeCycle=1;
        return 0;
      }
      if(color_[v]!=1){
        Q_.push(v);
        color_[v]=1;
      }
    }
  }

  //No negative weight cycle. Start to print the shortest path.
  vertex now=destination;
  vertex last=G.pi[now];
  while(now!=s){
    G.AnsWeight += w[last][now];
    G.AnsPath.push(now);
    now=last;
    last=G.pi[now];
  }
  G.AnsPath.push(s);
  G.ExistNegativeCycle=0;
  return 1;
}


int main(){
  //input start
  int V,E;
  cin>>V>>E;
  graph G(V,E);
  int sourse,destination;
  cin>>sourse>>destination;
  for(int i=0;i<E;i++){
    int tmp1,tmp2,tmp3;
    cin>>tmp1 >> tmp2 >> tmp3;
    edge tmp(tmp1,tmp2,tmp3);
    G.Edges.push_back(tmp);
  }
  //input finish


  //test original vertion
  double t=clock();
  BellmanFord(G,sourse,destination);
  t=clock()-t;
  cout<<"original time: "<<1000*t/CLOCKS_PER_SEC<<" ms"<<endl;
  // G.PrintAns();


  //test modified vertion
  t=clock();
  modified_BellmanFord(G,sourse,destination);
  t=clock()-t;
  cout<<"modified time: "<<1000*t/CLOCKS_PER_SEC<<" ms"<<endl;
  G.PrintAns();
}
