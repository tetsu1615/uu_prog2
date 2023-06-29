#include "array_utils.h"

int array_utils_vector_add(vector* vec1, const vector* vec2, const vector* vec3) {
    int i;
    if ((vec1->size != vec2->size) || (vec1->size != vec3->size)) {
        return 0;
    }
    for (i = 0; i < vec1->size; ++i) {
        vec1->val[i] = vec2->val[i] + vec3->val[i];
    }
    return 1;
}

int array_utils_vector_sub(vector* vec1, const vector* vec2, const vector* vec3) {
    int i;
    if ((vec1->size != vec2->size) || (vec1->size != vec3->size)) {
        return 0;
    }
    for (i = 0; i < vec1->size; ++i) {
        vec1->val[i] = vec2->val[i] - vec3->val[i];
    }
    return 1;
}

int array_utils_matrix_add(matrix* mat1, const matrix* mat2, const matrix* mat3) {
    int i, j;
    if ((mat1->size1 != mat2->size1) || (mat1->size1 != mat3->size1) || (mat1->size2 != mat2->size2) || (mat1->size2 != mat3->size2)) {
        return 0;
    }
    for (i = 0; i < mat1->size1; ++i) {
        for (j = 0; j < mat1->size2; ++j) {
            mat1->val[i][j] = mat2->val[i][j] + mat3->val[i][j];
        }
    }
    return 1;
}

int array_utils_matrix_sub(matrix* mat1, const matrix* mat2, const matrix* mat3) {
    int i, j;
    if ((mat1->size1 != mat2->size1) || (mat1->size1 != mat3->size1) || (mat1->size2 != mat2->size2) || (mat1->size2 != mat3->size2)) {
        return 0;
    }
    for (i = 0; i < mat1->size1; ++i) {
        for (j = 0; j < mat1->size2; ++j) {
            mat1->val[i][j] = mat2->val[i][j] - mat3->val[i][j];
        }
    }
    return 1;
}

int array_utils_matrix_mul(matrix* mat1, const matrix* mat2, const matrix* mat3) {
    int i, j, k;
    if ((mat1->size1 != mat2->size1) || (mat1->size2 != mat3->size2) || (mat2->size2 != mat3->size1)) {
        return 0;
    }
    for (i = 0; i < mat1->size1; ++i) {
        for (j = 0; j < mat1->size2; ++j) {
            mat1->val[i][j] = 0.0;
            for (k = 0; k < mat2->size2; ++k) {
                mat1->val[i][j] += mat2->val[i][k] * mat3->val[k][j];
            }
        }
    }
    return 1;
}

int array_utils_matrix_vector_mul(vector* vec1, const matrix* mat, const vector* vec2) {
    int i, j;
    if ((vec1->size != mat->size1) || (vec2->size != mat->size2)) {
        for (i = 0; i < vec1->size; ++i) {
            vec1->val[i] = 200;
        }
        return 0;
    }
    for (i = 0; i < vec1->size; ++i) {
        vec1->val[i] = 0.0;
        for (j = 0; j < mat->size2; ++j) {
            vec1->val[i] += mat->val[i][j] * vec2->val[j];
        }
    }
    return 1;
}