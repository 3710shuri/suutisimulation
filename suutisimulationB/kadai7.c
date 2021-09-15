#include <stdio.h>
#include <math.h>

int main(){
  double x0 = 1;
  double xt = -1;
  double k1,k2,k3,k4,h;
  double l1,l2,l3,l4;
  double tv,j,t;
  double pi = 3.14159265358979323846;
  int i;

  h=2*pi/10;
  t=h;
  for(i=1;i<=10;i++){
    k1 = xt;
    l1 = -2*x0 -2*xt;
    k2 = xt+h*l1/2;
    l2 = -2*(x0+h*k1/2) -2*(xt+h*l1/2);
    k3 = xt+h*l2/2;
    l3 = -2*(x0+h*k2/2) -2*(xt+h*l2/2);
    k4 = xt + h*l3;
    l4 = -2*(x0+h*k3) -2*(xt+h*l3);

    tv = exp(-1.0*t) * cos(t);
    t += h;

    x0= x0 + h/6 * (k1+2*k2+2*k3+k4);
    xt= xt + h/6 * (l1+2*l2+2*l3+l4);

    printf("x%d : %2.9f\n",i,x0);
    printf("true value : %2.9f\n",tv);
  }
}