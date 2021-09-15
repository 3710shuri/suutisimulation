#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, m, n, dim, maxline;
    double temp, alpha, reserve, sum1, sum2;
double A[4][4]={{2,3,0,0},{1,4,1,0},{0,1,2,1},{0,0,3,4}};
double L[3][3],U[3][3];
double b[4]={2,3,4,5};
double x[4],y[4];

    for(i = 0; i < 4; i++){
        L[i][i] = 1.0;
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if( i <= j){
                sum1 = 0.0;
                for(m = 0; m <= i-1; m++){
                    sum1 += L[i][m] * U[m][j];
                }
                U[i][j] = A[i][j] - sum1;
            }
            else if(i > j){
                sum2 = 0.0;
                for(n = 0; n <= j-1; n++){
                    sum2 += L[i][n] * U[n][j];
                }
                L[i][j] = (A[i][j] - sum2) / U[j][j];
            }
        }
    }

//  Ly = b
    for(i = 0; i < 4; i++){
        y[i] = b[i];
    }

    for(j = 0; j < 3; j++){
        for(i = j+1; i < 4; i++){
            y[i] -= y[j] * L[i][j];
        }
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