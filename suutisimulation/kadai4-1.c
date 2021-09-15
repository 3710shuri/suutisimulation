#include <stdio.h>
#include <math.h>

int main(void){
  int i;
  double x1,x2,y1,y2,z1,z2;

  x1 = 0;
  y1 = 0;
  z1 = 0;

  for(i = 1;i<=15;i++){
    x2 = (10.6 - y1 + z1)/4;
    y2 = (15.1 - x1 - z1)/3;
    z2 = (7.3 - x1 + y1)/3;
    x1 = x2;
    y1 = y2;
    z1 = z2;
    printf("%d : %.3f ; %.3f ; %.3f\n",i,x1,y1,z1);
  }


  return 0;
}