#include <iostream>
#include<iomanip>

using namespace std;

const int MaxVal = 9999;

const int n = 7;
//搜索到根节点和虚拟键的概率
double p[n + 1] = {-1,0.04,0.06,0.08,0.02,0.1,0.12,0.14};
double q[n + 1] = {0.06,0.06,0.06,0.06,0.05,0.05,0.05,0.05};

int root[n + 1][n + 1];//记录根节点
double w[n + 2][n + 2];//子树概率总和
double e[n + 2][n + 2];//子树期望代价

void optimalBST(double *p,double *q,int n)
{
    //初始化只包括虚拟键的子树
    for (int i = 1;i <= n + 1;++i)
    {
        w[i][i - 1] = q[i - 1];
        e[i][i - 1] = q[i - 1];
    }

    //由下到上，由左到右逐步计算
    for (int len = 1;len <= n;++len)
    {
        for (int i = 1;i <= n - len + 1;++i)
        {
            int j = i + len - 1;
            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            //求取最小代价的子树的根
            for (int k = i;k <= j;++k)
            {
                double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if (temp < e[i][j])
                {
                    e[i][j] = temp;
                    root[i][j] = k;
                }
            }
        }
    }
}
void printE(){
  cout<<"E="<<endl;
  for(int i=1;i<n+2;i++){
    for(int j=0;j<n+1;j++){
      cout <<setw(4)<< e[i][j]<<"  ";
    }
    cout<<endl;
  }
}
//输出最优二叉查找树所有子树的根
void printRoot()
{
    cout << "subtree's root~" << endl;
    for (int i = 1;i <= n;++i)
    {
        for (int j = 1;j <= n;++j)
        {
            cout << root[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//打印最优二叉查找树的结构
//打印出[i,j]子树，它是根r的左子树和右子树
void printOptimalBST(int i,int j,int r)
{
    int rootChild = root[i][j];//子树根节点
    if (rootChild == root[1][n])
    {
        //输出整棵树的根
        cout << "k" << rootChild << "is root" << endl;
        printOptimalBST(i,rootChild - 1,rootChild);
        printOptimalBST(rootChild + 1,j,rootChild);
        return;
    }

    if (j < i - 1)
        return;
    else if (j == i - 1)//遇到虚拟键
    {
        if (j < r)
            cout << "d" << j << "is" << "k" << r << "left" << endl;
        else
            cout << "d" << j << "is" << "k" << r << "right" << endl;
        return;
    }
    else//遇到内部结点
    {
        if (rootChild < r)
            cout << "k" << rootChild << "is" << "k" << r << "left" << endl;
        else
            cout << "k" << rootChild << "is" << "k" << r << "right" << endl;
    }

    printOptimalBST(i,rootChild - 1,rootChild);
    printOptimalBST(rootChild + 1,j,rootChild);
}

int main()
{
    optimalBST(p,q,n);
    printRoot();
    printE();
    cout << "bestBST" << endl;
    printOptimalBST(1,n,-1);
}
