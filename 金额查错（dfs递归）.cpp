/*金额查错（dfs递归）*/
/*输入描述（6，5，3，2，4，3，1）
用户输入的第一行是:有错的总金额。
一个整数 n，表示下面将要输入的明细账目的条数。
n 行整数，分别表示每笔账目的金额。
假设所有的金额都是整数;
每笔金额不超过1000，金额的明细条数不超过 100。
输出描述（1 2 4，1 3 3，3 4）
所有可能漏掉的金额组合。每个情况1行。
金额按照从小到大排列，中间用空格分开。
*/

#include <iostream>
#include <algorithm>
using namespace std;
int v[105],ms,s=0,n,a[105],j;

//dfs递归
void dfs(int i,int sum){
  //递归边界1
  if(sum==s-ms){
    for(i=0;i<n;i++)
      if(v[i]==1)
         cout<<a[i]<<' ';
    cout<<endl;
    return ;
  }
  //递归边界2
  if(i==n) 
    return ;
  //递归关系式  
  if(i<n&&i>1){
    if(a[i]==a[i-1]&&v[i-1]==0)//排除重复情况
      i++;
  }
  v[i]=1;//遍历过
  dfs(i+1,sum+a[i]);
  //回溯
  v[i]=0;
  dfs(i+1,sum);
  return ;
}
int main()
{
  cin>>ms>>n;
  for(j=0;j<n;j++){
    cin>>a[j];
    s+=a[j];
  }
  //排序
  sort(a,a+n);
  dfs(0,0);
  return 0;
}