
#include <stdio.h>
#include "matr.h"
#include <stdlib.h>
#include <math.h>
int main(){
    FILE *filematr = fopen("zei.txt", "r");
    double **A = fmatrica(filematr);
    int n = stringMatr(filematr);

    double *c = malloc(sizeof(double) * n);
    c[0] = 49.0;
    c[1] = 91.0;
    c[2] = 155.0;
    c[3] = 120.0;
    c[4] = 52.0;
    double *x = malloc(sizeof(double) * n);
    double *xx = malloc( sizeof( double) * n);

    double e = 0.000001;

    int k = 0;

    while (1){
        k += 1;
        printf(" Итерация №%i: \n", k );
        for (int i = 0; i < n; i ++) {
            xx[i] = c[i];
            for (int j = 0; j < n; j ++) {
                if (j < i ) xx[i] = xx[i] - A[i][j] * xx[j];
                else if (j > i) xx[i] = xx[i] - A[i][j] * x[j];
            }
        xx[i] = xx[i] / A[i][i];
        }

        int how_many = 0;
        for (int i = 0; i < n; i ++ ) {
            printf(" %f ", xx[i]);
            if (fabs( x[i] - xx[i]) < e) how_many += 1;
            x[i] = xx[i];
        }
        printf(" \n ");
        if ( how_many == n) break;
    }

}
