#include <stdio.h>
#include "matr.h"
#include <stdlib.h>
int main(){
    FILE *fileM = fopen("REV.txt", "r");
    double **matr = fmatrica(fileM);
    int string = stringMatr(fileM);
    int column = columnMatr(fileM);
    printf(" %i %i \n ", string, column);

    printMatr(matr,string,column);

    double *c = malloc(sizeof(double) * string);
    for (int i = 0; i < string; i ++) c[i] = matr[i][i];

    for (int i = 0; i < string; i ++) printf(" %f ", c[i]);
    printf(" \n ");


    double *f = malloc(sizeof(double) * string);
    for (int i = 0; i < string; i ++) f[i] = matr[i][column - 1] ;

    for (int i = 0; i < string; i ++) printf(" %f ", f[i]);


    double *l = malloc(sizeof(double) * (string - 1) );

    for (int i = 0; i < string ; i++) l[i] = matr[i][i - 1];
    printf(" \n ");
    for (int i = 0; i < string ; i ++) printf(" %f ", l[i]);

    double *r = malloc( sizeof(double) * (string - 1) );

    for (int i = 0; i < string - 1; i ++) r[i] = matr[i][i + 1];
    printf(" \n ");
        for (int i = 0; i < string - 1; i ++) printf(" %f ", r[i]);

    double *x = malloc( sizeof(double) * string);
    double *p = malloc( sizeof(double) * string);
    double *q = malloc( sizeof(double) * string);

    p[string - 1] = (f[string - 1] - l[string - 1] * p[string - 2]) / (c[string - 1] - l[string - 1] * q[string - 1]);
    x[string - 1] = p[string - 1];

    for (int n = string - 2; n > 0; n --) {
        p[n] = (f[n]- l[n] * p[n - 1]) / (c[n] - l[n] * q[n - 1] );
        q[n] = r[n] / (c[n] - l[n] * q[n - 1]) ;
        x[n] = p[n] - q[n] * x[n + 1];
    }
    p[0] = f[0] / c[0];
    q[0] = r[0] / c[0];
    x[0] = p[0] - q[0] * x[1];


    printf(" \n ");
    for (int i = 0; i < string; i ++) printf(" %.4f ", x[i]);





}
