#include <stdio.h>

#define N 16
typedef int fix_matrix[N][N];

void fix_set_diag(fix_matrix A, int val){
    int *Abase = &A[0][0];
    int iend = N * (N + 1);
    int i = 0;
    do {
        Abase[i] = val;
        i += (N + 1);
    }while (i != iend);
}


void fix_set_diag_second(fix_matrix A, int val){
    int *Abase = &A[0][0];
    int iend = N * (N + 1);
    int i = 0;
    do {
        Abase[i] = val;
        i += (N + 1);
    }while (i != iend);
}
