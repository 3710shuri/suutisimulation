#include <stdio.h>
#include <math.h>

int main(){
double A[4][4]={{2,3,0,0},{1,4,1,0},{0,1,2,1},{0,0,3,4}};
double L[4][4] = {{0,0,0,0},{A[1][0],0,0,0},{0,A[2][1],0,0},{0,0,A[3][2],0}};
double U[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
double b[4]={2,3,4,5};
double x[4],y[4];
int i,j;

// LとUを求める
L[0][0] = A[0][0];

for(i=1;i<4;i++){
  U[i-1][i] = A[i-1][i]/L[i-1][i-1];
  L[i][i] = A[i][i] - L[i][i-1]*U[i-1][i];
}

//  Ly = b

for(i=0;i<4;i++){
  y[i]=b[i];
  for(j=0;j<i;j++){
    y[i] -= y[j]*L[i][j];
  }
  y[i]/=L[i][i];
}

//  Ux = y
for(i = 0; i < 4; i++){
    x[i] = y[i];
}

for(j = 3; j >= 0; j--){
    x[j] /= U[j][j];
    for (i = 0; i <= j-1; i++){
        x[i] -= U[i][j] * x[j];
    }
}

printf("x= %f:y= %f:z= %f:u= %f",x[0],x[1],x[2],x[3]);

}