#include <stdio.h>
#include <math.h>

double simpson(int n){
  int N = n*2;
  double y[N+1],x[N+1],I,A;
  double h = 1.0/N;
  int i;

  for(i=0;i<=N;i++){
    x[i] = i * h;
    y[i] = x[i]*x[i]*x[i];
    printf("y%d = %f\n",i,y[i]);
  }
  A = y[0] + y[N];
  for(i=1;i<=n;i++){
    A += 4.0 * y[2*i-1];
  }

  for(i=1;i<=n-1;i++){
    A +=2 * y[2*i];
  }
  A = A * h/3.0;
  I = 0.25;
  printf("%f\n",A);
  return A - I;
}

int main(){
  printf("error=%f \n",fabs(simpson(4)));
  
}