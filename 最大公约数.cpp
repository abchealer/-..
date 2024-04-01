/*最大公约数*/
/*最大公倍数=（a*b）/最大公约数  */
#include<iostream>
#include<string.h>
using namespace std;
/*欧几里得算法（辗转相除法）*/
//算法要义：假设A=qB+R;则(A,B)=(B,R)的最大公约束相等
int main()
{
    int a, b;
    int c;
    cin>>a>>b;
    int big=a>b?a:b;
    int small = a+b-big;

    while (small)
    {
        c=small;
        small=big%small;
        big=c;
    }
    cout<<big;
    
    
    return 0;
}
/*短除法（耗时大）*/
int main(){
    int a, b,i;
    cin>>a>>b;
    int big=a>b?a:b;
    int small = a+b-big;
    for(;small>=1;small--){
        if(a%small==0 && b%small==0){
            cout<<small<<endl;
            break;
        }
    }
    return 0;
}