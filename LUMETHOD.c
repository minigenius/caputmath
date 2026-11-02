#include <stdio.h>
#include "matr.h"
#include <stdlib.h>
// 36 25 29 36 32
int main(){
    FILE *fMatr = fopen("MLU.txt" , "r");
    double **A  = fmatrica(fMatr);
    printMatr(A, stringMatr(fMatr),columnMatr(fMatr));

    int string = stringMatr(fMatr);
    int column = columnMatr(fMatr);

    double **L = malloc(sizeof(double*) * column);
    for (int i = 0; i < string; i ++) L[i] = malloc (sizeof(double) * column);

    double **U = malloc(sizeof(double*) * column);
    for (int i = 0; i < string; i ++) U[i] = malloc (sizeof(double) * column);

    for (int i = 0; i < string; i ++) L[i][0] = A[i][0]; 
    
    for (int i = 0; i < string; i ++) L[i][0] = A[i][0]; 
    

}
