#include <stdio.h>
#include "matr.c"
#include <stdlib.h>
#define M 10
#define N 11
int main(){
    double **matr = malloc(sizeof(double *) * M);
    for ( int i = 0; i < M; i ++) matr[i] = malloc(sizeof(double) * N );

    for (int i = 0; i < M; i++) for (int j = 0; j < N; j ++) matr[i][j] = 0;

    printMatr(matr, M, N);
    double *x = malloc(sizeof(double) * M);
    for (int i = M - 1; i >= 0; i --) x[i] = i + 1;
    for (int i = M - 1; i >= 0; i --) printf("%.2f ", x[i]);
    printf("\n");
    for (int i = M - 2; i > -1; i --) for ( int j = N - 2; j > i; j --) matr[i][j] = x[j]; // как это работает???



    printMatr(matr, M, N);
}
