#include <stdio.h>
#include "matr.h"
int main(){
    FILE *filematr = fopen("matr.txt","r" );
    double **B = fmatrica(filematr);
    int n = 5;
    for (int k = 0; k < n; k ++) {

        for (int i = 0; i < n; i ++) {
            for (int j = k + 1; j <= 2 * n - 1; j ++) {
                if ( i != k) B[i][j] = (B[i][j] * B[k][k] - B[k][j] * B[i][k]) / B[k][k];
            }
        }
    for ( int i = 0; i < n; i ++) {
        if (i != k) B[i][k] = 0;
            }

    for (int j = 2 * n - 1; j >= k; j --) B[k][j] = B[k][j] / B[k][k];

    }


    printMatr(B, 5, 10);
}
