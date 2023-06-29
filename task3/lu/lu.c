#include "lu.h"

double lu_decomp(matrix* L, matrix* U, const matrix* A) {
    int i, j, k;
    int n = A->size1;
    double det;

    /* AをLにコピー */
    matrix_copy(L, A);
    det = 1.0;
    for (i = 0; i < n; ++i) {
        det *= L->val[i][i];
        /* Lの計算 */
        /* l_{j,i} = 0, (j=0,...,i-1) */
        for (j = 0; j < i; ++j) {
            L->val[j][i] = 0.0;
        }
        /* Uの計算 */
        /* u_{i,j} = 0, (j=0,...,i-1) */
        for (j = 0; j < i; ++j) {
            U->val[i][j] = 0.0;
        }
        /* u_{i,i} = 1 */
        U->val[i][i] = 1.0;
        /* u_{i,j} = a_{i,j}/l_{i,i}, (j=i+1,...,n-1) */
        for (j = i + 1; j < n; ++j) {
            U->val[i][j] = L->val[i][j] / L->val[i][i];
        }
        /* Aの再計算 */
        /* A-lu^T */
        for (j = i + 1; j < n; ++j) {
            for (k = i + 1; k < n; ++k) {
                L->val[j][k] -= L->val[j][i] * U->val[i][k];
            }
        }
    }
    return det;
}

void lu_solve(vector* x, const matrix* L, const matrix* U, const vector* b) {
    /* ここを実装せよ */
    int i, j;
    int n = b->size;
    for (i = 0; i < n; i++) {
        x->val[i] = b->val[i];
        for (j = 0; j < i; j++) {
            x->val[i] -= L->val[i][j] * x->val[j];
        }
        x->val[i] /= L->val[i][i];
    }
    for (i = n - 1; i >= 0; i--) {
        for (j = i + 1; j < n; j++) {
            x->val[i] -= U->val[i][j] * x->val[j];
        }
    }
}