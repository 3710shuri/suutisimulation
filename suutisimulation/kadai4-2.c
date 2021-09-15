#include <stdio.h>
#include <math.h>

int main(void){
  int i;
  double x1,y1,z1;

  x1 = 0;
  y1 = 0;
  z1 = 0;

  for(i = 1;i<=15;i++){
    x1 = 2.65 - 0.25 * y1 + 0.25 * z1;
    y1 = 15.1/3 - x1/3 - z1/3;
    z1 = 7.3/3 - x1/3 + y1/3;
    printf("%d : %.3f ; %.3f ; %.3f\n",i,x1,y1,z1);
  }


  return 0;
}