 #include <stdio.h>
 #include <math.h>
 int main(){
    //精度问题(1) x<= N/2,N是奇数的话，x是double型 (2) log2里面的x/N也是double型，得乘1.0;,,
     double   x;
     int N=23333333;
     double ans=11625907.5798,eps=1e-4;//误差是10的-4次方，11625907.5797<result && result<11625907.5799

     for(x=0;x<N/2+1;x++){
         
         double    v=N-x;
         double res=-1.0*x*(x/N)*log2(x/N*1.0)-1.0*v*(v/N)*log2(v/N*1.0);
         if(fabs(res-ans)<eps)   
 			printf("x=%.0f  result=%.0f\n",x,res);
            
       
     }
        
     return 0;
 }


