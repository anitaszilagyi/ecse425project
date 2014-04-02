#include "ecse425projOPT.h"
#include "ecse425proj.h"
#include <stdio.h>
#include <stdlib.h>

const DLayout dlayoutOPT = RowMaj;

int min (int a, int b) {
	if (a < b)
	  return a;
	else return b;
}

void matVecMult_opt(int N, const double *matA, const double *vecB, double *vecC) 
{
    // Code in your optimized implementation here

    int i, j, ii, B;
    B = N/2;
    double temp = 0;
    for (i = 0; i < N; i++) {
        temp = 0;
        for (ii = 0; ii < N; ii = ii + B) {
           for (j = ii; j < min(ii + B, N); j++) {
                temp += matA[i * N + j] * vecB[j]; 
            }
        }
        vecC[i] = temp;
    }
        // Code in your naive implementation here
}

void matMult_opt(int N, const double *matA, const double *matB, double *matC) 
{
    // Code in your optimized implementation here

    int i, j, k, jj, kk;
    double tmp = 0;
    int B = N/2;
    //int dlayout = RowMaj;

    if(dlayoutOPT == RowMaj)
    {
   	for (jj = 0; jj < N; jj = jj + B) 
	for (kk = 0; kk < N; kk = kk + B)
        for (i = 0; i < N; i++) {
            for (j = jj; j < min(jj + B, N); j++) {
                tmp = 0;
		        for (k = kk; k < min(kk + B, N); k++) {
                    tmp += matA[i * N + k] * matB[k * N + j];
                }
		        matC[i * N + j] += tmp;
	        }
        }
    } else {

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                tmp = 0;
		for (k = 0; k < N; k++) {
                    tmp += matA[k * N + i] * matB[j * N + k];
                }
		matC[j * N + i] = tmp;
            }
        }
    }
}

