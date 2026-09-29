#include <stdio.h>
#ifndef MATR_H
#define MATR_H
int stringMatr(FILE *file_matr);
double **fmatrica(FILE *file_matr);
int columnMatr(FILE *file_matr);
void printMatr(double **matr, int n, int k);
double **switchStrMatr(double **matr, int swap_str, int swap_str2);
double **checkmatr(double **matr, int str, int now, int col);

#endif
