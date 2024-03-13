/*斐波那契数列*/
//0,1,1,2,3,5,8....
//F(N)=F(N-1)+F(N-2)
#include <stdio.h>
int n, sum=0,arr[100];
int result(int n){
     arr[0]=0;
     arr[1]=1;
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    else{
        //5+3
        return result(n-1)+result(n-2);
    }
    
     
}
int main(){
    scanf("%d", &n);
    printf("%d\n", result(n));
    return 0;
}