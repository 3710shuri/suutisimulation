#include <stdio.h>
#include <math.h>

int main(void){
  int i,N;
  double x1,x2,a,pi;
  a = 237;
  x1 = 1;
  x2 = 1;
  N = 1000;
 pi = 3.14159265358979323846;

  for(i=0;i<=N;i++){
    x1 = x2;
    x2 = x1 - (tan(x1)-a)*cos(x1)*cos(x1);
    if(fabs(tan(x2) - tan(x1))<=0.0000001){
      while(x2>pi){
        x2 = x2-pi;
      }
      printf("x = %f\n",x2);
      break;
    }else{
      if(i==1000){
        printf("238^(1/%f) : error \n",i);
      }
    }
  }
  return 0;
}