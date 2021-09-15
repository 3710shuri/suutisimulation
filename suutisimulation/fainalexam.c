#include<stdio.h>
#include<math.h>

double func (double x){ return x - 2*sin(x); }
double dfunc(double x){ return 1 - 2*cos(x);} //1 - 2*cos(x)を追加

int main(){
int i; double x;

x = 2.0;
for(i=0; i<10; i++) x-=func(x)/dfunc(x);
printf("%.10f %.10e\n",x, func(x));

return 0;
}