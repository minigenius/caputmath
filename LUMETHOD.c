#include <stdio.h>
#include "matr.h"
#include <stdlib.h>
// 36 25 29 36 32
int main(){
    FILE *fMatr = fopen("MLU.txt" , "r");
    double **A  = fmatrica(fMatr);


    int string = stringMatr(fMatr);
    int column = columnMatr(fMatr);

    double *freeA = malloc(sizeof(double) * string);
    freeA[0] = 36.0;
    freeA[1] = 25.0;
    freeA[2] = 29.0;
    freeA[3] = 36.0;
    freeA[4] = 32.0;


    double **L = malloc(sizeof(double*) * column);
    for (int i = 0; i < string; i ++) L[i] = malloc (sizeof(double) * column);

    double **U = malloc(sizeof(double*) * column);
    for (int i = 0; i < string; i ++) U[i] = malloc (sizeof(double) * column);

    for (int i = 0; i < string; i ++) L[i][0] = A[i][0];

    for (int j = 0; j < string; j ++) U[0][j] = A[0][j] / L[0][0];

    for (int k = 1; k < string; k ++) {

       for (int i = k; i < string; i ++) {
           double sum = 0.0;
           for (int m = 0; m <= k - 1; m ++) sum += L[i][m] * U[m][k];
           L[i][k] = A[i][k] - sum;
       }


       for (int j = k ; j < string; j ++) {
           double sum = 0.0;
           for (int m = 0; m <= k - 1; m ++) sum += L[k][m] * U[m][j];
           U[k][j] = 1 / L[k][k] * ( A[k][j] - sum);
       }

    }

    printMatr(L, column, column);
    printf("\n");
    printMatr(U, column, column);
    printf("\n");

    double *y = malloc(sizeof(double) * column);
    y[0] = freeA[0] / L[0][0];

    for (int k = 1; k < string; k ++) {

        double sum = 0.0;

        for (int m = 0; m <= k - 1; m ++) sum += L[k][m] * y[m];
        y[k] = 1 / L[k][k] * (freeA[k] - sum);


    }

    double *x = malloc(sizeof(double) * column);
    x[column - 1] = y[column - 1];

    for ( int k = column - 2; k >= 0; k --)  {

        double sum = 0.0;

        for( int m = k + 1; m < string; m ++) sum += U[k][m] * x[m];
        x[k] = y[k] - sum;

    }

    for (int i = 0; i < string; i ++ ) printf(" %.2f ", x[i]);
    printf("\n");
    for (int i = 0; i < string; i ++ ) printf(" %.2f ", y[i]);
}
