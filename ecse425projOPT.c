#include "ecse425projOPT.h"
#include "ecse425proj.h"
#include <stdio.h>
#include <stdlib.h>

void matVecMult_opt(int N, const double *matA, const double *vecB, double *vecC) 
{
    // Code in your optimized implementation here

    int i, j;
    double temp = 0;
    for (i = 0; i < N; i++) {
        temp = 0;
        for (j = 0; j < N; j++) {
            temp += matA[i * N + j] * vecB[j]; 
        }
        vecC[i] = temp;
    }
        // Code in your naive implementation here
}

void matMult_opt(int N, const double *matA, const double *matB, double *matC) 
{
    // Code in your optimized implementation here

    int i, j, k;
    double tmp = 0;
    //int dlayout = RowMaj;

    //if(dlayout == RowMaj)
    //{
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                tmp = 0;
		for (k = 0; k < N; k++) {
                    tmp += matA[i * N + k] * matB[k * N + j];
                }
		matC[i * N + j] = tmp;
	    }
        }
    /*} else {

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                tmp = 0;
		for (k = 0; k < N; k++) {
                    tmp += matA[k * N + i] * matB[j * N + k];
                }
		matC[j * N + i] = tmp;
            }
        }
    }*/
}

