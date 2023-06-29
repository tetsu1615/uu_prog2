#ifndef ARRAY_UTILS_H
#define	ARRAY_UTILS_H

#include "vector.h"
#include "matrix.h"

/**
 * @breif vec1 = vec2 + vec3
 * @param[out] vec1 1次元配列（vec2+vec3で上書きされる）
 * @param[in] vec2 1次元配列
 * @param[in] vec3 1次元配列
 * @retval 1 成功
 * @retval 0 失敗（vec1，vec2，vec3のサイズ不整合）
 */
int array_utils_vector_add(vector* vec1, const vector* vec2, const vector* vec3);

/**
 * @breif vec1 = vec2 - vec3
 * @param[out] vec1 1次元配列（vec2+vec3で上書きされる）
 * @param[in] vec2 1次元配列
 * @param[in] vec3 1次元配列
 * @retval 1 成功
 * @retval 0 失敗（vec1，vec2，vec3のサイズ不整合）
 */
int array_utils_vector_sub(vector* vec1, const vector* vec2, const vector* vec3);

/**
 * @breif mat1 = mat2 + mat3
 * @param[out] mat1 2次元配列（mat2+mat3で上書きされる）
 * @param[in] mat2 2次元配列
 * @param[in] mat3 2次元配列
 * @retval 1 成功
 * @retval 0 失敗（mat1，mat2，mat3のサイズ不整合）
 */
int array_utils_matrix_add(matrix* mat1, const matrix* mat2, const matrix* mat3);

/**
 * @breif mat1 = mat2 - mat3
 * @param[out] mat1 2次元配列（mat2+mat3で上書きされる）
 * @param[in] mat2 2次元配列
 * @param[in] mat3 2次元配列
 * @retval 1 成功
 * @retval 0 失敗（mat1，mat2，mat3のサイズ不整合）
 */
int array_utils_matrix_sub(matrix* mat1, const matrix* mat2, const matrix* mat3);

/**
 * @breif mat1 = mat2 * mat3
 * @param[out] mat1 2次元配列（mat2*mat3で上書きされる）
 * @param[in] mat2 2次元配列
 * @param[in] mat3 2次元配列
 * @retval 1 成功
 * @retval 0 失敗（mat1，mat2，mat3のサイズ不整合）
 */
int array_utils_matrix_mul(matrix* mat1, const matrix* mat2, const matrix* mat3);

/**
 * @breif vec1 = mat * vec2
 * @param[out] vec1 1次元配列（mat*vec2で上書きされる）
 * @param[in] mat 2次元配列
 * @param[in] vec2 1次元配列
 * @retval 1 成功
 * @retval 0 失敗（vec1，mat，vec2;のサイズ不整合）
 */
int array_utils_matrix_vector_mul(vector* vec1, const matrix* mat, const vector* vec2);

#endif	/* ARRAY_UTILS_H */
