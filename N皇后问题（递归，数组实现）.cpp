/*N皇后问题
n<10
时间复杂度=O(N!)*/
#include<iostream>
#include<math.h>
using namespace std;

int path[11];
int n, i=1;
/*错误点：把j定义为了全局变量；把ans定义为了全局变量并=0
  修改：在N_DFS中把j,ans改为局部变量*/
//与之前的所有皇后进行check
int check(int path[], int i, int j){
    //对从[0]=0到当前行的皇后比较
    for(int k=0;k<i;k++){
        if(j==path[k] || abs(k-i)==abs(path[k]-j))
            return 0;
    }
        
    
        return 1;
}
//当前位置的递归
int N_DFS(int path[],int n, int i ){
    if(i==n)
        return 1;
        int ans=0;
    for(int j=0;j<n;j++){
        if(check(path,i, j)==1){
            path[i]=j;
            
            ans +=N_DFS(path, n, i+1);
            
        }
    }
    return ans;
}
int main(){
    cin>>n;
    
    if(n<=3)
        cout<<0<<endl;
    int ans = N_DFS(path,n,0);
    cout<<ans<<endl;


    return 0;
}