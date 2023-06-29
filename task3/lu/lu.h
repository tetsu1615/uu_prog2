#ifndef LU_H
#define LU_H

#include "vector.h"
#include "matrix.h"

/**
 * @brief LU分解（A=LU）
 * @param[out] L 下三角行列
 * @param[out] U 三角行列：対角成分は全て1
 * @param[in] A LU分解対象行列
 * @return 行列式
 */
double lu_decomp(matrix *L, matrix *U, const matrix *A);

/**
 * @brief LU分解を用いて連立方程式を解く
 * @param[out] x 解ベクトル
 * @param[in] L 三角行列
 * @param[in] U 上三角行列：対角成分は全て1
 * @param[in] b 右辺ベクトル
 */
void lu_solve(vector *x, const matrix *L, const matrix *U, const vector *b);

#endif /* LU_H */
