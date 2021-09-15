#include <stdio.h>
#include <math.h>

int main(){
  double x0 = 1;
  double x1 = 0;
  double x2 = 0;
  double tv,j;
  int i;

  tv = -1-1+2*exp(1);
printf("true value : %f\n",tv);
// h=0.1
// オイラー法
for(i=1;i<=10;i++){
  j = (i -1)* 0.1;
  x1=x0 + 0.1*(j + x0);
  x0 = x1;
}
printf("h=0.1\n %f\n",x1);
printf("|e| = %f\n",fabs(x1-tv));

x0=1;
x1=0;
// 改良オイラー法
for(i =1;i<=10;i++){
    j = (i-1) * 0.1;
    x1= x0 + 0.1*(j+x0)/2;
    x2 = x0 + 0.1*(j + 0.1/2 + x1);
    x0= x2;
}
printf("%f\n",x2);
printf("|e| = %f\n",fabs(x2-tv));


// h=0.2
// オイラー法
x0=1;
x1=0;
for(i=1;i<=5;i++){
  j = (i-1) * 0.2;
  x1=x0 + 0.2*(j + x0);
  x0 = x1;
}
printf("h=0.2\n%f\n",x1);
printf("|e| = %f\n",fabs(x1-tv));

x0=1;
x1=0;
x2 =0;
// 改良オイラー法
for(i =1;i<=5;i++){
    j = (i-1) * 0.2;
    x1= x0 + 0.2*(j+x0)/2;
    x2 = x0 + 0.2*(j + 0.2/2 + x1);
    x0= x2;
}
printf("%f\n",x2);
printf("|e| = %f\n",fabs(x2-tv));

// h=0.01
// オイラー法
x0=1;
x1=0;
for(i=1;i<=100;i++){
  j = (i-1) * 0.01;
  x1=x0 + 0.01*(j + x0);
  x0 = x1;
}
printf("h=0.01\n%f\n",x1);
printf("|e| = %f\n",fabs(x1-tv));

x0=1;
x1=0;
x2 =0;
// 改良オイラー法
for(i =1;i<=100;i++){
    j = (i-1) * 0.01;
    x1= x0 + 0.01*(j+x0)/2;
    x2 = x0 + 0.01*(j+ 0.01/2 + x1);
    x0= x2;
}
printf("%f\n",x2);
printf("|e| = %f\n",fabs(x2-tv));

return 0;
}