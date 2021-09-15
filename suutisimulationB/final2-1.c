#include <stdio.h>
#include <math.h>


int main(){
  double x = 1.0;
  double y = 0.0;
  double y1;
  double tv,j,h;
  int i;

  h=0.1;
  printf("y1.0 = %f |e|=%f\n",y,fabs(y-0));
// オイラー法
  for(i=1;i<=8;i++){
    y1 = 2.0 * sqrt(y-1.0*log(x))/x + 1.0/x;

    y = y + h * y1;
    tv = log(x) * log(x) + log(x);
    printf("y1.%d = %f |e|=%f\n",i,y,fabs(y-tv));
    x += h;

  }

  tv = log(1.8) * log(1.8) + log(1.8);
  printf("tv = %f\n",tv);
  printf("|e| = %f\n",fabs(y-tv));
  return 0;

}