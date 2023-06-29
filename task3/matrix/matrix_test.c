#include <stdlib.h>
#include "matrix.h"

int main(int argc, char** argv) {
    int i, j;
    int m, n;
    matrix mat1, mat2;

    /* 2�����z��̑傫���ݒ� */
    m = 3;
    n = 4;
    /* mat1�̗̈�m�� */
    matrix_new(m, n, &mat1);
    /* �v�f�̑�� */
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            mat1.val[i][j] = (i * 7 + 3 * j) - 5;
        }
    }
    /* mat1�̕\�� */
    printf("mat1 = \n");
    matrix_print(&mat1, "%f");
    /* mat2�̗̈�m�� */
    matrix_new(m, n, &mat2);
    /* 2�����z��̗v�f�̃R�s�[ */
    if (matrix_copy(&mat2, &mat1)) {
        /* mat2�̕\�� */
        printf("mat2 = \n");
        matrix_print(&mat2, "%f");
    }
    /* �̈�̊J�� */
    matrix_delete(&mat1);
    matrix_delete(&mat2);

    return EXIT_SUCCESS;
}
