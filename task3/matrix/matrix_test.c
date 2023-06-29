#include <stdlib.h>
#include "matrix.h"

int main(int argc, char** argv) {
    int i, j;
    int m, n;
    matrix mat1, mat2;

    /* 2次元配列の大きさ設定 */
    m = 3;
    n = 4;
    /* mat1の領域確保 */
    matrix_new(m, n, &mat1);
    /* 要素の代入 */
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            mat1.val[i][j] = (i * 7 + 3 * j) - 5;
        }
    }
    /* mat1の表示 */
    printf("mat1 = \n");
    matrix_print(&mat1, "%f");
    /* mat2の領域確保 */
    matrix_new(m, n, &mat2);
    /* 2次元配列の要素のコピー */
    if (matrix_copy(&mat2, &mat1)) {
        /* mat2の表示 */
        printf("mat2 = \n");
        matrix_print(&mat2, "%f");
    }
    /* 領域の開放 */
    matrix_delete(&mat1);
    matrix_delete(&mat2);

    return EXIT_SUCCESS;
}
