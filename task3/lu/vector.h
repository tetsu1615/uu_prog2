#ifndef VECTOR_H
#define	VECTOR_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct vector
 * @brief 1次元配列構造体
 */
typedef struct {
    int size; /**< サイズ */
    double* val; /**< 配列要素 */
} vector;

/**
 * @brief サイズnの1次元配列を動的に確保
 * @param[in] n サイズ
 * @param[out] vec 1次元配列
 */
void vector_new(int n, vector* vec);

/**
 * @brief 確保した1次元配列を開放
 * @param[in,out] vec 開放する1次元配列
 */
void vector_delete(vector* vec);

/**
 * @brief 1次元配列vec2をvec1にコピー
 * @param[out] vec1 コピー先
 * @param[in] vec2 コピー元
 * @retval 1 成功
 * @retval 0 失敗（vec1とvec2のサイズ不整合）
 */
int vector_copy(vector* vec1, const vector* vec2);

/**
 * @breif 1次元配列vecをformatに従って標準出力に表示
 * @param[in] vec 出力する1次元配列
 * @param[in] format 出力形式（prinfの第１引数）
 */
void vector_print(const vector* vec, const char* format);

#endif	/* VECTOR_H */
