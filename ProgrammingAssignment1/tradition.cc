#include<iostream>
#include"time.h"
using namespace std;
int main(){
  int A1[200][200]={{1,2},{3,4}};
  int A2[200][200]={{1,2},{3,4}};
  int A3[200][200]={{0,0},{0,0}};
  double start=clock();

  for(int i=0;i<200;i++){
	    for(int j=0;j<200;j++){
			for(int k=0;k<200;k++){
			    A3[i][j]+=A1[i][k]*A2[k][j];
			}
		}
	}




  double end=clock();
  cout<<start<<endl;
  cout<<end<<endl;
  return 0;
}
