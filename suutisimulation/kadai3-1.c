#include <stdio.h>
#include <math.h>

int main(void){
  int N,j;
  double x1,x2,i,c;
  N=1000;
  x1=1;
  c=238;

  for(i=2;i<=5;i++){
    for(j=0;j<=N;j++){
      x2 = x1 - (pow(x1,i)-c)/(i*pow(x1,i-1));
      x1=x2;
      if(fabs((pow(c,1/i) - x1))<=0.0000001){
        printf("238^(1/%f) = %f\n",i,x1);
        break;
      }else{
        if(i==1000){
          printf("238^(1/%f) : error \n",i);
        }
      }
    }
  }
  return 0;
}