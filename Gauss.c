#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "matr.h"


int main(){
    FILE *file_matr = fopen("matrich.txt", "r");
    if (file_matr == NULL) return 1;
    double **matr = fmatrica(file_matr);
    const int col = columnMatr(file_matr);
    const int string = stringMatr(file_matr);
    printMatr(matr, string, col);

    printf("%i %i \n", col, string);

    int minK;
    if (col > string) {  minK = string;}
    else { minK = col;}

    for (int k = 0; k < minK ; k ++){

        if (fabs(matr[k][k]) < 0.0001) {
            for (int i = k; i < string - 1; ++i) if (fabs(matr[i][k]) > 0.000001  ) {switchStrMatr(matr, k, i); break;}
        }
        checkmatr(matr, string, k, col);

        for (int i = k + 1; i < string - 1; i ++) {
            for (int j = k + 1; j < col - 1; j ++) {
                matr[i][j] =  (matr[i][j] * matr[k][k] - matr[i][k] * matr[k][j]) / matr[k][k];
            }
        }
        checkmatr(matr, string, k, col);

        for (int i = k + 1; i < string  ; i ++) {
            matr[i][k] = 0.0;
        }
        checkmatr(matr, string, k, col);


        for (int j = col - 1; j >= k; j --) matr[k][j] = matr[k][j] / matr[k][k];
    }

    double *x = malloc(sizeof(double) * string);
    for (int i = 0; i < string - 1; i ++) x[i] = i;
    x[string - 1] = matr[string - 1][col - 1];    // массив корней

    for ( int i = string - 2; i >= 0; i --){
        double sum = 0;
        int brolook;
        for ( int j = col - 2; j > i; j --) {sum += matr[i][j] * x[j]; brolook = x[j];}

        x[string - 2 - i] = matr[i][col - 1] - sum;
    }
    printMatr(matr, string, col);
    for (int i = 0; i < string; i ++) {
        printf("%.4f ", x[i]);
    }
}
