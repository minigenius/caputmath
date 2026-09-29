#include "matr.h"
#include <stdio.h>
#include <stdlib.h>

double **fmatrica(FILE *file_matr){
    int lengthMat = stringMatr(file_matr);
    int col = columnMatr(file_matr);
    double **matr = malloc(sizeof(double*) * lengthMat);
    for (int i = 0; i < lengthMat; i ++){
        matr[i] = malloc(sizeof(double) * col);
    }

    char s[100];

    double temp = 0;

    for (int i = 0; i < lengthMat; i ++) {
        for (int j = 0; j < col; j ++) {
            fscanf(file_matr, "%s", s);
            temp = strtod(s, NULL);
            matr[i][j] = temp;
        }
    }
    rewind(file_matr);
    return matr;
}

int stringMatr(FILE *file_matr){
    int a = 0;
    int cj = EOF;
    int length = 0;
    while ((a = fgetc(file_matr)) != EOF) {
        if (a == '\n')  length ++;
        cj = a;
    }
    if (cj != EOF && cj != '\n') length ++;

    rewind(file_matr);
    return length;
}

int columnMatr(FILE *file_matr){
    int a;
    int max = 0;
    int k = 0;
    while ((a = getc(file_matr)) != EOF){
        if (a == '.') k ++;
        if (k > max) max = k;
        if (a == '\n') k = 0;
    }
    rewind(file_matr);
    return max;
}

void printMatr(double **matr, int n, int k){
    for (int i = 0; i < n; ++ i ) {
        for (int j = 0; j < k; ++j){
            printf("%5.2f ", matr[i][j]);
        }
        printf("\n");
    }

}

double **switchStrMatr(double **matr, int swap_str, int swap_str2){
   double *tempPtr = matr[swap_str];
  matr[swap_str] = matr[swap_str2];
  matr[swap_str2] = tempPtr;
  return matr;
}



double **checkmatr(double **matr, int str, int now, int col){

    int flag = 0;
    for ( int i = 0; i < col - 1 ; ++i ) {
        if (matr[now][i] != 0) flag = 1;
    }

    if (matr[now][col - 1] == 0 && flag == 0) switchStrMatr(matr, now, str - 1);

    if (matr[now][col - 1] != 0 && flag == 0) {
        printf("Матрица несовместна");
        exit(EXIT_FAILURE);
    }
    return matr;
}
