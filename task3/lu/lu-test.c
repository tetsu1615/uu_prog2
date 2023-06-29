#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "lu.h"

/**
 *     / 8 16 24  32 \
 * A = | 2  7 12  17 |
 *     | 6 17 32  59 |
 *     \ 7 22 46 105 /
 *
 *     / 160 \
 * b = |  70 |
 *     | 198 |
 *     \ 291 /
 * @param[out] A 係数行列
 * @param[out] b 右辺ベクトル
 */
void set_equation1(matrix* A, vector* b) {
    /* 行列サイズ指定 */
    int N = 4;
    /* 領域確保 */
    matrix_new(N, N, A);
    vector_new(N, b);
    /* 係数行列要素指定 */
    A->val[0][0] = 8;
    A->val[0][1] = 16;
    A->val[0][2] = 24;
    A->val[0][3] = 32;
    A->val[1][0] = 2;
    A->val[1][1] = 7;
    A->val[1][2] = 12;
    A->val[1][3] = 17;
    A->val[2][0] = 6;
    A->val[2][1] = 17;
    A->val[2][2] = 32;
    A->val[2][3] = 59;
    A->val[3][0] = 7;
    A->val[3][1] = 22;
    A->val[3][2] = 46;
    A->val[3][3] = 105;
    /* 右辺ベクトル要素指定 */
    b->val[0] = 160;
    b->val[1] = 70;
    b->val[2] = 198;
    b->val[3] = 291;
}

/**
 *     / 3 2 1 \
 * A = | 2 4 3 |
 *     \ 1 3 5 /
 *
 *     /  6   \
 * b = | 10   |
 *     \ 12.5 /
 * @param[out] A 係数行列
 * @param[out] b 右辺ベクトル
 */
void set_equation2(matrix* A, vector* b) {
    /* 行列サイズ指定 */
    int N = 3;
    /* 領域確保 */
    matrix_new(N, N, A);
    vector_new(N, b);
    /* 係数行列要素指定 */
    A->val[0][0] = 3;
    A->val[0][1] = 2;
    A->val[0][2] = 1;
    A->val[1][0] = 2;
    A->val[1][1] = 4;
    A->val[1][2] = 3;
    A->val[2][0] = 1;
    A->val[2][1] = 3;
    A->val[2][2] = 5;
    /* 右辺ベクトル要素指定 */
    b->val[0] = 6;
    b->val[1] = 10;
    b->val[2] = 12.5;
}


/**
 *     / 1 2 2 \
 * A = | 3 6 2 |
 *     \ 1 1 1 /
 *
 *     / 1 \
 * b = | 7 |
 *     \ 5 /
 * @param[out] A 係数行列
 * @param[out] b 右辺ベクトル
 */
void set_equation3(matrix* A, vector* b) {
    /* 行列サイズ指定 */
    int N = 3;
    /* 領域確保 */
    matrix_new(N, N, A);
    vector_new(N, b);
    /* 係数行列要素指定 */
    A->val[0][0] = 1;
    A->val[0][1] = 2;
    A->val[0][2] = 2;
    A->val[1][0] = 3;
    A->val[1][1] = 6;
    A->val[1][2] = 2;
    A->val[2][0] = 1;
    A->val[2][1] = 1;
    A->val[2][2] = 1;
    /* 右辺ベクトル要素指定 */
    b->val[0] = 1;
    b->val[1] = 7;
    b->val[2] = 5;
}

int main(void) {
    int N; /* 行列サイズ */
    double det; /* 行列式 */
    matrix A; /* 係数行列 */
    vector b; /* 右辺ベクトル */
    matrix L; /* L */
    matrix U; /* U */
    vector x; /* 解ベクトル */
    char sw[2]; /* 方程式切替スイッチ */

    printf("input 1,2,3 ? ");
    fgets(sw, sizeof(sw), stdin);
    switch (atoi(sw)) {
    case 1:
        set_equation1(&A, &b);
        break;
    case 2:
        set_equation2(&A, &b);
        break;
    case 3:
        set_equation3(&A, &b);
        break;
    default:
        return EXIT_FAILURE;
    }
    /* 行列サイズ指定 */
    N = A.size1;
    /* 領域確保 */
    matrix_new(N, N, &L);
    matrix_new(N, N, &U);
    vector_new(N, &x);
    /* 係数行列表示 */
    printf("A =\n");
    matrix_print(&A, "%f");
    /* 右辺ベクトル表示 */
    printf("b = ");
    vector_print(&b, "%f");
    /* LU分解 */
    det = lu_decomp(&L, &U, &A);
    /* LとUを表示 */
    printf("L =\n");
    matrix_print(&L, "%f");
    printf("U =\n");
    matrix_print(&U, "%f");
    /* 行列式表示 */
    printf("det = %3.0f\n", det);
    /* LU分解を用いて連立方程式を解く */
    lu_solve(&x, &L, &U, &b);
    /* 解ベクトル表示 */
    printf("x = ");
    vector_print(&x, "%f");
    /* 領域解放 */
    matrix_delete(&A);
    matrix_delete(&L);
    matrix_delete(&U);
    vector_delete(&b);
    vector_delete(&x);

    return EXIT_SUCCESS;
}
