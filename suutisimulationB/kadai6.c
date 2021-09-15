#include <stdio.h>
#include <math.h>

int main(){
  double x0 = 0;
  double x1 = 0;
  double k1,k2,k3,k4,h;
  double tv,j;
  int i;

  h=0.1;
  for(i=1;i<=10;i++){
        // x=e^t
    // k1 = x0;
    // k2 = x0 + h*k1/2;
    // k3 = x0 + h*k2/2;
    // k4 = x0 + h*k3;
    
    // x=tan(t)
    k1 = 1 + x0 * x0;
    k2 = 1 + (x0 + h*k1/2)*(x0 + h*k1/2);
    k3 = 1 + (x0 + h*k2/2)*(x0 + h*k2/2);
    k4 = 1 + (x0 + h*k3)*(x0 + h*k3);


    x1= x0 + h/6 * (k1+2*k2+2*k3+k4);
    x0 = x1;
    printf("x%d : %2.7f\nk1 : %2.7f k2 : %2.7f k3 : %2.7f k4 : %2.7f\n",i,x1,k1,k2,k3,k4);
  }
  return 0;
}