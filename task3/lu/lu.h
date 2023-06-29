#ifndef LU_H
#define LU_H

#include "vector.h"
#include "matrix.h"

/**
 * @brief LU�����iA=LU�j
 * @param[out] L ���O�p�s��
 * @param[out] U �O�p�s��F�Ίp�����͑S��1
 * @param[in] A LU����Ώۍs��
 * @return �s��
 */
double lu_decomp(matrix *L, matrix *U, const matrix *A);

/**
 * @brief LU������p���ĘA��������������
 * @param[out] x ���x�N�g��
 * @param[in] L �O�p�s��
 * @param[in] U ��O�p�s��F�Ίp�����͑S��1
 * @param[in] b �E�Ӄx�N�g��
 */
void lu_solve(vector *x, const matrix *L, const matrix *U, const vector *b);

#endif /* LU_H */
