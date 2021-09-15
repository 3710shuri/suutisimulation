#include <stdio.h>
#include <math.h>

int main(void){
  double a[3][4]={{2,-1,1,6},{-1,4,-2,-4},{1,-2,3,9}};
  double b[1][4];
  double x[3];
  double m,p,q;
  int i,j,k,l,pivot;

          for(i=0;i<3;i++) {
                m=0;
                pivot=i;

                for(l=i;l<3;l++) {
/*i列の中で一番値が大きい行を選ぶ*/
                        if(fabs(a[l][i])>m) {
                                m=fabs(a[l][i]);
                                pivot=l;
                        }
                }

/*pivotがiと違えば、行の入れ替え*/
                if(pivot!=i) {  
                        for(j=0;j<4;j++) {
                                b[0][j]=a[i][j];        
                                a[i][j]=a[pivot][j];
                                a[pivot][j]=b[0][j];
                        }
                }
        }

        for(k=0;k<3;k++) {
                p=a[k][k];              
                a[k][k]=1;      

                for(j=k+1;j<4;j++) {
                        a[k][j]/=p;
                }

                for(i=k+1;i<3;i++) {
                        q=a[i][k];

                        for(j=k+1;j<4;j++) {
                                a[i][j]-=q*a[k][j];
                        }
                a[i][k]=0;
                }
        }

/*解の計算*/
        for(i=2;i>=0;i--) {
                x[i]=a[i][3];
                for(j=2;j>i;j--) {
                        x[i]-=a[i][j]*x[j];
                }
        }


  printf("x=%f:y=%f:z=%f",x[0],x[1],x[2]);

}