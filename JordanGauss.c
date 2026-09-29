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

        for (int i = 0; i < string - 1; i ++) {
            for (int j = k + 1; j < col - 1; j ++) {
               if (i != k) matr[i][j] =  (matr[i][j] * matr[k][k] - matr[i][k] * matr[k][j]) / matr[k][k];
            }
        }
        checkmatr(matr, string, k, col);

        for (int i = 0; i < string  ; i ++) {
           if(i != k) matr[i][k] = 0.0;
        }
        checkmatr(matr, string, k, col);


        for (int j = col - 1; j >= k; j --) matr[k][j] = matr[k][j] / matr[k][k];
    }


    printMatr(matr, string, col);

}
