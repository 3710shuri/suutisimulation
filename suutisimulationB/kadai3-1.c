#include <stdio.h>
#include <math.h>

int main (){
 double x0[4] = {-0.8611363115,-0.3399810435,0.3399810435,0.8611363115};
 double w[4] = {0.3478548451,0.6521451548,0.6521451548,0.3478548451};
 double x[4];
 double A = 0;
 double I,E;
 int i;

 for(i =0;i<4;i++){
   x[i] = (1.0 + x0[i])/2.0;
   A += w[i]/(2*sqrt( x[i]* x[i] + 237.0));
 }

I = log((1 + sqrt(1+237.0))/sqrt(237.));
 printf("A = %f\n",A);
 printf("I = %f\n",I);
E = fabs(I-A);
 printf("I - A = %3.3e\n",E);
 return 0;
}