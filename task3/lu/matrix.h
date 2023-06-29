#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct matrix
 * @brief 2次元配列構造体
 */
typedef struct
{
    int size1;    /**< 行数 */
    int size2;    /**< 列数 */
    double **val; /**< 配列要素 */
} matrix;

/**
 * @brief m×nの2次元配列を動的に確保
 * @param[in] m 行数
 * @param[in] n 列数
 * @param[out] mat 2次元配列
 */
void matrix_new(int m, int n, matrix *mat);

/**
 * @brief 確保した2次元配列を開放
 * @param[in,out] mat 開放する2次元配列
 */
void matrix_delete(matrix *mat);

/**
 * @brief 2次元配列mat2をmat1にコピー
 * @param[out] mat1 コピー先
 * @param[in] mat2 コピー元
 * @retval 1 成功
 * @retval 0 失敗（mat1とmat2のサイズ不整合）
 */
int matrix_copy(matrix *mat1, const matrix *mat2);

/**
 * @brief 2次元配列matをformatに従って標準出力に表示
 * @param[in] mat 出力する2次元配列
 * @param[in] format出力形式（prinfの第1引数）
 */
void matrix_print(const matrix *mat, const char *format);

#endif /* MATRIX_H */
