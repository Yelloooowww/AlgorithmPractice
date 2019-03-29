#include<iostream>
using namespace std;

void print_Maxtrix(int *A,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<*(A+i*n+j)<<"("<< (A+i*n+j)<<")"<<" ";
    }
    cout<<endl;
  }
}

void add(int *A,int *B,int *C,int n){
  cout<<"add_n="<<n<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      *(C+(i*4+j))=*(A+(i*n+j))+*(B+(i*n+j));
      cout<<"add:"<<*(A+(i*n+j))<<"+"<<*(B+(i*n+j))<<"="<<*(C+(i*4+j))<<endl;
    }
  }
}


void sub(int *A,int *B,int *C,int n){

  cout<<"minus_n="<<n<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      *(C+(i*4+j))=*(A+(i*n+j))-*(B+(i*n+j));
      cout<<"add:"<<*(A+(i*n+j))<<"-"<<*(B+(i*n+j))<<"="<<*(C+(i*4+j))<<endl;
    }
  }
}

void multiply(int *A,int *B,int *C,int n){
  cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^multiply_n="<<n<<endl;
  print_Maxtrix( A,n);
  print_Maxtrix( B,n);
  cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<n<<endl;
  if(n<=1){
    cout<<"n=1111111111111111111111111111111111111111111111111111111"<<endl;
    cout<<"A="<<*A<<"B="<<*B<<endl;
    *C = (*A)*(*B);
    print_Maxtrix( C,n);
    return;
  }else if(n>1){
    int M1[n/2][n/2];
    int M2[n/2][n/2];
    int M3[n/2][n/2];
    int M4[n/2][n/2];
    int M5[n/2][n/2];
    int M6[n/2][n/2];
    int M7[n/2][n/2];
    int tmp1[n/2][n/2];
    int tmp2[n/2][n/2];
    int C11[n/2][n/2];
    int C12[n/2][n/2];
    int C21[n/2][n/2];
    int C22[n/2][n/2];
    for(int i=0;i<(n*n/4);i++){
      *(&M1[0][0]+i)=0;
      *(&M2[0][0]+i)=0;
      *(&M3[0][0]+i)=0;
      *(&M4[0][0]+i)=0;
      *(&M5[0][0]+i)=0;
      *(&M6[0][0]+i)=0;
      *(&M7[0][0]+i)=0;
      *(&tmp1[0][0]+i)=0;
      *(&tmp2[0][0]+i)=0;
      *(&C11[0][0]+i)=0;
      *(&C12[0][0]+i)=0;
      *(&C21[0][0]+i)=0;
      *(&C22[0][0]+i)=0;
    }

    cout<<"  M1=(A11+A22)(B11+B22)"<<endl;
    add(A+(0*2+0)*((n*n)/4),A+(1*2+1)*((n*n)/4),&tmp1[0][0],n/2);
    add(B+(0*2+0)*((n*n)/4),B+(1*2+1)*((n*n)/4),&tmp2[0][0],n/2);
    multiply(&tmp1[0][0],&tmp2[0][0],&M1[0][0],n/2);
    cout<<"  M2=(A21+A22)B11"<<endl;
    add(A+(1*2+0)*((n*n)/4),A+(1*2+1)*((n*n)/4),&tmp1[0][0],n/2);
    multiply(&tmp1[0][0],B+(0*2+0)*((n*n)/4),&M2[0][0],n/2);
    cout<<"  M3=A11(B12-B22)"<<endl;
    sub(B+(0*2+1)*((n*n)/4),B+(1*2+1)*((n*n)/4),&tmp1[0][0],n/2);
    multiply(&tmp1[0][0],A+(0*2+0)*((n*n)/4),&M3[0][0],n/2);
    cout<<"  M4=A22(B22-B11)"<<endl;
    sub(B+(1*2+1)*((n*n)/4),B+(0*2+0)*((n*n)/4),&tmp1[0][0],n/2);
    multiply(&tmp1[0][0],A+(1*2+1)*((n*n)/4),&M4[0][0],n/2);
    cout<<"  M5=(A11+A12)B22"<<endl;
    add(A+(0*2+0)*((n*n)/4),A+(0*2+1)*((n*n)/4),&tmp1[0][0],n/2);
    multiply(&tmp1[0][0],B+(1*2+1)*((n*n)/4),&M5[0][0],n/2);
    cout<<"  M6=(A21-A11)(B11+B12)"<<endl;
    sub(A+(1*2+0)*((n*n)/4),A+(0*2+0)*((n*n)/4),&tmp1[0][0],n/2);
    add(B+(0*2+0)*((n*n)/4),B+(0*2+1)*((n*n)/4),&tmp2[0][0],n/2);
    multiply(&tmp1[0][0],&tmp2[0][0],&M6[0][0],n/2);
    cout<<"  M7=(A12-A22)(B21+B22)"<<endl;
    sub(A+(0*2+1)*((n*n)/4),A+(1*2+1)*((n*n)/4),&tmp1[0][0],n/2);
    add(B+(1*2+0)*((n*n)/4),B+(1*2+1)*((n*n)/4),&tmp2[0][0],n/2);
    multiply(&tmp1[0][0],&tmp2[0][0],&M7[0][0],n/2);

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"M1:"<<endl;
    print_Maxtrix(&M1[0][0],n/2);
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    cout<<"   C11=M1+M4-M5+M7"<<endl;
    add(&M1[0][0],&M4[0][0],&C11[0][0],n/2);
    sub(&C11[0][0],&M5[0][0],&C11[0][0],n/2);
    add(&C11[0][0],&M7[0][0],&C11[0][0],n/2);
    cout<<"   C12=M3+M5"<<endl;
    add(&M3[0][0],&M5[0][0],&C12[0][0],n/2);
    cout<<"   C21=M2+M4"<<endl;
    add(&M2[0][0],&M4[0][0],&C21[0][0],n/2);
    cout<<"   C22=M1-M2+M3+M6"<<endl;
    sub(&M1[0][0],&M2[0][0],&C22[0][0],n/2);
    add(&C22[0][0],&M3[0][0],&C22[0][0],n/2);
    add(&C22[0][0],&M6[0][0],&C22[0][0],n/2);

    for(int j=0;j<((n*n)/4);j++){
      *(C+0*((n*n)/4)+j)=*(&C11[0][0]+j);
    }
    for(int j=0;j<((n*n)/4);j++){
      *(C+1*((n*n)/4)+j)=*(&C12[0][0]+j);
    }
    for(int j=0;j<((n*n)/4);j++){
      *(C+2*((n*n)/4)+j)=*(&C21[0][0]+j);
    }
    for(int j=0;j<((n*n)/4);j++){
      *(C+3*((n*n)/4)+j)=*(&C22[0][0]+j);
    }
  }
  cout<<"&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
  print_Maxtrix( C,n);
  cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
}

int main(){
  // int A[1][1]={3};
  // int B[1][1]={9};
  // int C[1][1];
  int A[2][2]={{0,1},{2,3}};
  int B[2][2]={{7,6},{5,4}};
  int C[2][2];
  // int A[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  // int B[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  // int C[4][4];
  // add(&A[0][0],&B[0][0],&C[0][0],2);
  // cout<<"A:"<<A<<endl;
  // print_Maxtrix(&A[0][0],2);
  // cout<<"B:"<<endl;
  // print_Maxtrix(&B[0][0],2);
  multiply(&A[0][0],&B[0][0],&C[0][0],2);




  return 0;
}
