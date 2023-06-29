#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(void) {
    int n;
    vector vec1, vec2;

    /* 1次元配列のサイズ設定 */
    n = 4;
    /* vec1の領域確保 */
    vector_new(n, &vec1);
    /* 要素の代入 */
    vec1.val[0] = 0.2;
    vec1.val[1] = 1.3;
    vec1.val[2] = 2.5;
    vec1.val[3] = 3.6;
    /* vec1の要素の表示 */
    printf("vec1 = ");
    vector_print(&vec1, "%f");
    /* vec2の領域確保 */
    vector_new(n, &vec2);
    /* 1次元配列の要素のコピー */
    if (vector_copy(&vec2, &vec1)) {
        /* vec2の要素の表示 */
        printf("vec2 = ");
        vector_print(&vec2, "%f");
    }
    /* 領域の開放 */
    vector_delete(&vec1);
    vector_delete(&vec2);

    return EXIT_SUCCESS;
}
