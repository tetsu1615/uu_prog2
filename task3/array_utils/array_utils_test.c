#include <stdlib.h>
#include "array_utils.h"

int main(int argc, char** argv) {
    int i, j;
    int l, m, n;
    vector vec1, vec2, vec3, vec4;
    matrix mat1, mat2, mat3, mat4, mat5;
    /* ベクトル・行列サイズ */
    l = 3;
    m = 2;
    n = 3;
    /* ベクトル */
    vector_new(n, &vec1);
    vector_new(n, &vec2);
    vector_new(n, &vec3);
    vector_new(m, &vec4);
    /* 行列 */
    matrix_new(m, n, &mat1);
    matrix_new(m, n, &mat2);
    matrix_new(m, n, &mat3);
    matrix_new(l, m, &mat4);
    matrix_new(l, n, &mat5);
    printf("##### vector #####\n");
    /* vec1の初期化 */
    for (i = 0; i < n; i++) {
        vec1.val[i] = 3 * i + 1;
    }
    /* vec1の表示 */
    printf("vec1 = ");
    vector_print(&vec1, "%f");
    /* vec1をvec2にコピー */
    vector_copy(&vec2, &vec1);
    /* vec2の表示 */
    printf("vec2 = ");
    vector_print(&vec2, "%f");
    /* vec3 = vec1 + vec2 */
    array_utils_vector_add(&vec3, &vec1, &vec2);
    /* vec3の表示 */
    printf("vec3 = vec1 + vec2 = ");
    vector_print(&vec3, "%f");
    /* vec3 = vec1 - vec2 */
    array_utils_vector_sub(&vec3, &vec1, &vec2);
    /* vec3の表示 */
    printf("vec3 = vec1 - vec2 = ");
    vector_print(&vec3, "%f");

    printf("##### matrix #####\n");
    /* mat1の初期化 */
    for (i = 0; i < mat1.size1; ++i) {
        for (j = 0; j < mat1.size2; ++j) {
            mat1.val[i][j] = i + j;
        }
    }
    /* mat1の表示 */
    printf("mat1 =\n");
    matrix_print(&mat1, "%f");
    /* mat1をmat2にコピー */
    matrix_copy(&mat2, &mat1);
    /* mat2の表示 */
    printf("mat2 =\n");
    matrix_print(&mat2, "%f");
    /* mat3 = mat1 + mat2*/
    array_utils_matrix_add(&mat3, &mat1, &mat2);
    /* mat3の表示 */
    printf("mat3 =\n");
    matrix_print(&mat3, "%f");
    /* mat3 = mat1 - mat2*/
    array_utils_matrix_sub(&mat3, &mat1, &mat2);
    /* mat3の表示 */
    printf("mat3 =\n");
    matrix_print(&mat3, "%f");

    printf("##### vector & matrix #####\n");
    /* mat4の初期化 */
    for (i = 0; i < mat4.size1; ++i) {
        for (j = 0; j < mat4.size2; ++j) {
            mat4.val[i][j] = i + j;
        }
    }
    /* mat4の表示 */
    printf("mat4 =\n");
    matrix_print(&mat4, "%f");
    /* mat5 = mat4 * mat1 */
    array_utils_matrix_mul(&mat5, &mat4, &mat1);
    /* mat5の表示 */
    printf("mat5 =\n");
    matrix_print(&mat5, "%f");
    /* vec4 = mat1 * vec1 */
    array_utils_matrix_vector_mul(&vec4, &mat1, &vec1);
    /* vec4の表示 */
    printf("vec4 = ");
    vector_print(&vec4, "%f");

    return EXIT_SUCCESS;
}
