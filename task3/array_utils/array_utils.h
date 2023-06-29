#ifndef ARRAY_UTILS_H
#define	ARRAY_UTILS_H

#include "vector.h"
#include "matrix.h"

/**
 * @breif vec1 = vec2 + vec3
 * @param[out] vec1 1�����z��ivec2+vec3�ŏ㏑�������j
 * @param[in] vec2 1�����z��
 * @param[in] vec3 1�����z��
 * @retval 1 ����
 * @retval 0 ���s�ivec1�Cvec2�Cvec3�̃T�C�Y�s�����j
 */
int array_utils_vector_add(vector* vec1, const vector* vec2, const vector* vec3);

/**
 * @breif vec1 = vec2 - vec3
 * @param[out] vec1 1�����z��ivec2+vec3�ŏ㏑�������j
 * @param[in] vec2 1�����z��
 * @param[in] vec3 1�����z��
 * @retval 1 ����
 * @retval 0 ���s�ivec1�Cvec2�Cvec3�̃T�C�Y�s�����j
 */
int array_utils_vector_sub(vector* vec1, const vector* vec2, const vector* vec3);

/**
 * @breif mat1 = mat2 + mat3
 * @param[out] mat1 2�����z��imat2+mat3�ŏ㏑�������j
 * @param[in] mat2 2�����z��
 * @param[in] mat3 2�����z��
 * @retval 1 ����
 * @retval 0 ���s�imat1�Cmat2�Cmat3�̃T�C�Y�s�����j
 */
int array_utils_matrix_add(matrix* mat1, const matrix* mat2, const matrix* mat3);

/**
 * @breif mat1 = mat2 - mat3
 * @param[out] mat1 2�����z��imat2+mat3�ŏ㏑�������j
 * @param[in] mat2 2�����z��
 * @param[in] mat3 2�����z��
 * @retval 1 ����
 * @retval 0 ���s�imat1�Cmat2�Cmat3�̃T�C�Y�s�����j
 */
int array_utils_matrix_sub(matrix* mat1, const matrix* mat2, const matrix* mat3);

/**
 * @breif mat1 = mat2 * mat3
 * @param[out] mat1 2�����z��imat2*mat3�ŏ㏑�������j
 * @param[in] mat2 2�����z��
 * @param[in] mat3 2�����z��
 * @retval 1 ����
 * @retval 0 ���s�imat1�Cmat2�Cmat3�̃T�C�Y�s�����j
 */
int array_utils_matrix_mul(matrix* mat1, const matrix* mat2, const matrix* mat3);

/**
 * @breif vec1 = mat * vec2
 * @param[out] vec1 1�����z��imat*vec2�ŏ㏑�������j
 * @param[in] mat 2�����z��
 * @param[in] vec2 1�����z��
 * @retval 1 ����
 * @retval 0 ���s�ivec1�Cmat�Cvec2;�̃T�C�Y�s�����j
 */
int array_utils_matrix_vector_mul(vector* vec1, const matrix* mat, const vector* vec2);

#endif	/* ARRAY_UTILS_H */
