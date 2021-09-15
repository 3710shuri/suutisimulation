#include <stdio.h>
#include <math.h>

int main(){
  double x = 1.0;
  double y = 0.0;
  double k1,k2,k3,k4,h,x1,x2,x3,y1,y2,y3;
  double tv,j;
  int i;

  h=0.4;
  for(i=1;i<=2;i++){
    k1 = 2.0 * sqrt(y-1.0*log(x))/x + 1.0/x;
    x1 = x + h/2.0;
    y1 = y + h*k1/2.0;
    k2 = 2.0 * sqrt(y1-1.0*log(x1))/x1 + 1.0/x1;
    x2 = x + h/2.0;
    y2 = y + h*k2/2.0;
    k3 = 2.0 * sqrt(y2-1.0*log(x2))/x2 + 1.0/x2;
    x3 = x + h;
    y3 = y + h*k3;
    k4 = 2.0 * sqrt(y3-1.0*log(x3))/x3 + 1.0/x3;

    y = y + h/6 * (k1+2*k2+2*k3+k4);
    x = 1.0 + h*i;
    tv = log(x) * log(x) + log(x);

    printf("k1 = %f\nk2 = %f\nk3 = %f\nk4 = %f\n",k1,k2,k3,k4);
    printf("y1.%d : %2.7f |e| = %f\n",i*4,y,fabs(y-tv));
  }
  return 0;
}