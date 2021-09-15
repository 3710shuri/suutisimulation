#include <stdio.h>
#include <math.h>

int main(void){
  int i;
  double x1,y1,z1,u1,x2,y2,z2,u2;

  x1 = 0;
  y1 = 0;
  z1 = 0;
  u1 = 0;

  for(i = 1;i<=100;i++){
    x2 = x1;
    y2 = y1;
    z2 = z1;
    u2 = u1;
    x1 = 29/8 - y1/8 - (3/8)*z1 - u1/8;
    y1 = 37/7 - x1/7 - z1/7 - u1/7;
    z1 = 23.7/6 - x1/6 - y1/6 - u1/6;
    u1 = 8.2 - x1/5 -0.4*y1 - z1/5;

    if(fabs(x2 - x1)<=0.0000001 && fabs(y2 - y1)<=0.0000001 && fabs(z2 - z1)<=0.0001 && fabs(u2 - u1)<=0.0000001){
      printf("%d : %.3f ; %.3f ; %.3f : %.3f\n",i,x1,y1,z1,u1);
      break;
    }
  }


  return 0;
}