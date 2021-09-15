#include <stdio.h>
#include <math.h>

int main (){
 double x0[3] = {-1.0*sqrt(3.0/5.0),0,sqrt(3.0/5.0)};
 double w[3] = {5.0/9.0,8.0/9.0,5.0/9.0};
 double x[3];
 double A = 0;
 double tv,E;
 int i;

 for(i =0;i<3;i++){
   x[i] = (1.0 + x0[i])/2.0;
   A += w[i] * x[i] * x[i] * x[i]/2.0;
   printf("x0%d = %f\n",i,x0[i]);
   printf("x%d = %f\n",i,x[i]);
 }

tv = 0.25;
 printf("A = %f\n",A);
 printf("tv = %f\n",tv);
E = fabs(tv-A);
 printf("tv - A = %3.3e\n",E);
 return 0;
}