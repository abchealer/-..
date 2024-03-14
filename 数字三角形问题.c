/*误解：贪心，每一行往下取最大，不对
  正解:从低向上每行求和，求到最顶端二选一中的max得到答案*/
#include <stdio.h>
int main(){
    int arr[100][100],n,i,j;
    scanf("%d", &n);
    for( i=1;i<=n;i++){
        for( j=1;j<=i;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i=n;i>=2;i--){//求到arr[i-1]=arr[1]，所以i到2
        for(int j=1;j<=i;j++){
            if(arr[i][j] > arr[i][j+1]){
                arr[i-1][j] += arr[i][j];
            }
            else{
                arr[i-1][j] += arr[i][j+1];
            }
        }
    }
    
    printf("%d", arr[1][1]);
    return 0;
}