#include <stdio.h>
#include <math.h>

int main(){
  double x0 = 0;
  double x1 = 0;
  double x2 = 0;
  double tv1,tv2,j;
  int i;

  printf("x0 : 0\n");
  for(i =1;i<=10;i++){
    // x1= x0 + 0.1*x0/2;
    // x2 = x0 + 0.1*x1;
    // x0= x2;
    // tv1 = exp(0.1*(i));
    // tv2 = exp(0.1*i);
    // printf("x%d : %2.15f : %2.15f : %2.15f\n",i + 1/2,x1,tv1,fabs(x1-tv1));
    // printf("x%d : %2.15f : %2.15f : %2.15f\n",i,x2,tv2,fabs(x2-tv2));

    x1 = x0 + 0.1*(1 + x0*x0)/2;
    x2 = x0 + 0.1*(1 + x1*x1);
    x0 = x2;
    j = i-0.5;
    tv1 = tan(j*0.1);
    tv2 = tan(i*0.1);
    printf("x%1.1f : %2.15f : %2.15f : %2.15f\n",j,x1,tv1,fabs(x1-tv1));
    printf("x%d : %2.15f : %2.15f : %2.15f\n",i,x2,tv2,fabs(x2-tv2));
  }
  return 0;
}