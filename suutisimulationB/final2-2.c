#include <stdio.h>
#include <math.h>


int main(){
  double x = 1.0;
  double y = 0.0;
  double y0,y1,y2;
  double tv,j,h;
  int i;

  h=0.2;
  printf("y0 = %f\n",y);
// 改良オイラー法
  for(i=1;i<=4;i++){
    y1 = 2.0 * sqrt(y-1.0*log(x))/x + 1.0/x;

    y0 = y + h/2 * y1;
    x += 0.1;
    tv = log(x) * log(x) + log(x);
    printf("y1.%d = %f |e| = %f\n",i*2-1,y0,fabs(y0-tv));

    y2 = 2.0 * sqrt(y0-1.0*log(x))/x + 1.0/x;
    y = y + h * y2;
    x += h/2.0;
    tv = log(x) * log(x) + log(x);
    printf("y1.%d = %f |e| = %f\n",i*2,y,fabs(y-tv));

  }

  tv = log(1.8) * log(1.8) + log(1.8);
  printf("tv = %f\n",tv);
  printf("|e| = %f\n",fabs(y-tv));
  return 0;

}
