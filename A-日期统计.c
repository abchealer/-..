#include <stdio.h>
//子序列(正确的日期)与父序列(在数组中找到2023以后的序列)对比。
//通过isZi函数判断，头相同往下比；头不同子不变父加一；例如：子序列123，父1723，头相同，比较"23","723";头不同，比较"23","23"...
int isZi(char *zxl,char*fxl){
    if(*zxl == '\0')//子序列到头：zxl是fxl的子序列
        return 1;
    if(*fxl == '\0')//父序列到头: 子序列没到头，明显的，zxl不是fxl的子序列
        return 0;
    if(*zxl == *fxl){
        return isZi(zxl+1,fxl+1);
    }
    return isZi(zxl, fxl+1);
}
int main(){
    //2.isZi函数判断，并记录个数
    int sum=0;
    //1.表示出正确日期
    char data[5]="";
    for(int month=1;month<=12;month++){
        int day[12+1]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=1;i<=day[month];i++){
            sprintf(data,"%02d",month);//sptintf: 将两个序列格式化存进data序列中，如0101,0102...
            sprintf(data+2,"%02d",i);//data+2: i序列插入data[2]位置上
            //puts(data);测试一下
            sum += isZi(data,"3 8 5 1 6 3 4 6 7 0 7 8 2 7 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3");

        }
        
    }
    printf("%d", sum);
    return 0;
}