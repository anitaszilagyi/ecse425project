#include "ecse425proj.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Specify the data layout format */
const DLayout dlayout = ColMaj;

void randInitialize(int sz, double *vPtr)
{
    int i;
    for (i = 0; i < sz; i++)
        vPtr[i] = drand48();
}

void displayVec(int sz, const double *vPtr)
{
    if(dlayout == RowMaj)
    {
        int i;
        printf("[");
        for (i = 0; i < sz; i++)
        {
            printf("%e",vPtr[i]);
            if(i < sz-1)
                printf(",");
            else
                printf("]");
        }
    }
}

void displayMat(int rows, int cols, const double *vPtr)
{
    if(dlayout == RowMaj)
    {
        int i;
        printf("[\n");
        for (i = 0; i < rows; i++) {
            displayVec(cols, &vPtr[i*rows]);
            printf("\n");
        }
        printf("]");
    }
}

void matMult(int N, const double *matA, const double *matB, double *matC)
{
     int i, j, k;
    if(dlayout == RowMaj)
    {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) 
                for (k = 0; k < N; k++) {
                    matC[i * N + j] += matA[i * N + k] * matB[k * N + j]; 
                }
        }
    } else {

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                for (k = 0; k < N; k++) {
                    matC[j * N + i] += matA[k * N + i] * matB[j * N + k];
                }
            }
        }
    }
        //     for (i = 0; i < N * N; i++) {
        //     printf("%f ", matC[i]);
        // }
}

void matVecMult(int N, const double *matA, const double *vecB, double *vecC)
{
    
    int i, j;
    if(dlayout == RowMaj)
    {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) 
                vecC[i] += matA[i * N + j] * vecB[j]; 
        }

        // Code in your naive implementation here
    } else {

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) 
                vecC[i] += matA[j * N + i] * vecB[j]; 
        }        

    }
        //     for (i = 0; i < N; i++) {
        //     printf("%f ", vecC[i]);
        // }
}

double compareVecs(int N, const double *src, const double *ref)
{
    double ds = 0., ss = 0.;
    int i;
    for(i = 0; i < N; i++)
    {
        ds += (src[i] - ref[i]) * (src[i] - ref[i]);
        ss += ref[i] * ref[i];
    }
    ss = ds/ss;
    printf("Error SQUARED is: %e\n",ss);
    return ss;
}
