#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matr.h"
int main(){
    FILE *filematr = fopen("holecki.txt", "r");
    int string = stringMatr(filematr);
    double **matr = fmatrica(filematr);

    double *B = malloc(sizeof(double) * string);
    B[0] = 24.0;
    B[1] = 24.0;
    B[2] = 22.0;
    B[3] = 26.0;
    B[4] = 36.0;

    double **L = malloc(sizeof(double *) * string);
    for (int i = 0; i < string; i ++) L[i] = malloc(sizeof(double) * string);

    double **U = malloc(sizeof(double *) * string);
    for ( int i = 0; i < string; i ++) U[i] = malloc(sizeof(double) * string);

    L[0][0] = sqrt(matr[0][0]);
    for (int i = 1; i < string; i ++) L[i][0] = matr[i][0] / L[0][0];
    L[1][1] = sqrt(matr[1][1] - L[1][0] * L[1][0]);
    for (int i = 2; i < string; i ++) L[i][1] = ( matr[i][1] - L[i][0] * L[1][0]) /  L[1][1];
    for ( int k = 2; k < string; k ++) {

        double sum = 0.0;
        for (int j = 0; j <= k - 1; j++) sum += L[k][j] * L[k][j];
        L[k][k] = sqrt( matr[k][k] - sum );

        for (int i = k + 1; i < string; i ++) {

            double sum2 = 0.0;
            for (int j = 0; j <= k - 1; j++) sum2 += L[i][j] * L[k][j];
            L[i][k] = (matr[i][k] - sum2) / L[k][k];
        }

    }


  for (int i = 0; i < string; i++ ){
      for (int j = 0; j < string; j ++ ) U[j][i] = L[i][j];
  }


  printf(" \n  ");
  printMatr(U, string, string);

  double *x = malloc(sizeof(double) * string);
  double *y = malloc(sizeof(double) * string);
  y[0] = B[0] / L[0][0];

      for (int k = 1; k < string; k ++) {

          double sum = 0.0;

          for (int m = 0; m <= k - 1; m ++) sum += L[k][m] * y[m];
          y[k] = 1 / L[k][k] * (B[k] - sum);


      }

      x[string - 1] = y[string - 1];

      for ( int k = string - 2; k >= 0; k --)  {

          double sum = 0.0;
          for( int m = k + 1; m < string; m ++) sum += U[k][m] * x[m];
          x[k] = y[k] - sum;

      }

      for (int i = 0; i < string; i++) printf(" %.4f ", x[i]);
      for (int i = 0; i < string; i++) printf(" %.4f ", y[i]);

}
