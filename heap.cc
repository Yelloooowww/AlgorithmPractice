#include<iostream>
#include<vector>

#define NegativeInfinity -2147483648
using namespace std;

class node_heap{
private:
  int value;
public:
  node_heap(int v=0){ value=v;}
  void set_value(int v){value=v;}
  int get_value(){return value;}
};

class heap{
private:
  vector<node_heap> vec;
public:
  int size(){
    return vec.size();
  }
  void insert(node_heap i) {vec.push_back(i);}
  void MAX_HEAPIFY(int index){
    int largest;
    int l=2*index;
    int r=2*index+1;
    if(l<=vec.size() && vec[l-1].get_value()>vec[index-1].get_value()){
      largest=l;
    }else{
      largest=index;
    }
    if(r<=vec.size() && vec[r-1].get_value()>vec[largest-1].get_value()){
      largest=r;
    }
    if(largest !=index){
      // cout<<"*exchange "<<vec[largest-1].get_value()<<"<->"<<vec[index-1].get_value()<<endl;
      node_heap tmp=vec[largest-1];
      vec[largest-1]=vec[index-1];
      vec[index-1]=tmp;
      MAX_HEAPIFY(largest);
    }
  }
  void BUILD_MAX_HEAP(){
    for(int i=(vec.size()/2);i>0;i--) MAX_HEAPIFY(i-1);
  }

  int HEAP_MAXIMUM(){return vec[0].get_value();}
  int HEAP_EXTRACT_MAX(){
    // cout<<"vec.size="<<vec.size()<<endl;
    if(vec.size()<1){
      cout<<"error:heap overflow"<<endl;
      return -1;
    }
    int max=vec[0].get_value();
    vec[0]=vec[vec.size()-1];
    vec.pop_back();
    MAX_HEAPIFY(1);
    return max;
  }

  void HEAP_INCREASE_KEY(int index,int key){
    if(vec[index-1].get_value() >key){
      cout<<"error:nwe key is smaller than current key"<<endl;
      return ;
    }
    vec[index-1].set_value(key);
    int i=index;
    while (i>1 && vec[(i/2)-1].get_value()<vec[i-1].get_value()) {
      // cout<<"exchange "<<vec[(i/2)-1].get_value()<<"<->"<<vec[i-1].get_value()<<endl;
      node_heap tmp=vec[(i/2)-1];
      vec[(i/2)-1]=vec[i-1];
      vec[i-1]=tmp;
      i=i/2;
    }
  }

  void MAX_HEAP_INSERT(int key){
    vec.push_back(NegativeInfinity);
    HEAP_INCREASE_KEY(vec.size(),key);
  }

  friend ostream& operator<< (ostream& out,heap foo){
    for(int i=0;i<foo.vec.size();i++) out<<foo.vec[i].get_value()<<" ";
    out<<endl;
    return out;
  }
};

vector<int> heap_sorting(vector<int> a){
  heap for_sorting;
  vector<int> ans;
  for(int i=0;i<a.size();i++){
    for_sorting.MAX_HEAP_INSERT(a[i]);
    // cout<<for_sorting;
  }
  for(int i=0;i<a.size();i++){
    ans.push_back(for_sorting.HEAP_EXTRACT_MAX());
  }
  return ans;
}
int main(){
  vector<int> A={4,1,3,2,16,9,10,14,8,7};
  // heap B;
  // for(int i=0;i<10;i++){
  //   node_heap j(A[i]);
  //   B.insert(j);
  // }
  //
  // cout<<B;
  // B.BUILD_MAX_HEAP();
  // cout<<B;
  //
  // B.HEAP_INCREASE_KEY(9,15);
  // cout<<B;
  cout<<"before :";
  for(int i=0;i<10;i++) cout<<A[i]<<" ";
  cout<<endl<<"after sorting :";
  A=heap_sorting(A);
  for(int i=0;i<10;i++) cout<<A[i]<<" ";








  return 0;
}
