#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"



void transpose(double mat[], size_t lines,size_t cols, double res[])
{
    for(unsigned i = 0; i < lines; i++){
        for(unsigned j = 0; j < cols; j ++){
            res[i + j * lines] = mat[j + i * cols];
        }
    }
}

void add(double mat1[], double mat2[], size_t lines, size_t cols, double res[]){
    for(unsigned i = 0; i < lines; i++){
        for(unsigned j = 0; j < cols; j ++){
            res[j + i * cols] = mat1[j + i * cols] + mat2[j + i * cols];
        }
    }
}

void mul(double m1[], double m2[], size_t n, size_t m, size_t p, double res[]){
    for (unsigned i = 0; i < m; i++){
        for(unsigned j = 0 ; j < p ; j++){
            int res_digit = 0;
            for(unsigned h = 0; h < n; h++){
                res_digit += m1[h + i*m] * m2[j + h * p];
            }
            res[j + i * p] = res_digit;
        }
    }
}

void print_matrix(double mat[], size_t lines, size_t cols){
    for (unsigned i = 0; i < lines ; i++){
        for (unsigned j = 0; j < cols; j ++){
            printf("%4g",mat[j + i * cols]);
        }
        printf("\n");
    }
}
