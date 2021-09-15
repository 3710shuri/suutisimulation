#include <stdio.h>
#include <math.h>

double daikei(int n){
  double y[n+1],x[n+1],I,E,A;
  double h = 1.0/n;
  int i;

  for(i=0;i<=n;i++){
    x[i] = i * h;
    y[i] = 1.0/sqrt( x[i]* x[i] + 237.0);
  }
  A = (y[0] + y[n])/2.0;
  for(i=1;i<n;i++){
    A += y[i];
  }
  A *= h;
  I = log((1 + sqrt(1+237.0))/sqrt(237));
  printf("A = %f\n",A);
  return A-I;
}

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
  int N = 200000;
  int N2 = 200;
  int n;
  
  // for(n=1000;n<=200000;n++){
  //   daikei(n);
  //   if(fabs(daikei(n))<= 6.488e-12){
  //     printf("%d\n",n+1);
  //     break;
  //   }
  // }

  // for(n=0;n<=200000;n++){
  //   simpson(n);
  //   if(fabs(simpson(n))<= 6.488e-12){
  //     printf("%d\n",n*2+1);
  //     break;
  //   }
  // }

  printf("error=%f \n",fabs(simpson(4)));
  
}