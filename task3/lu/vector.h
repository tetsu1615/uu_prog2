#ifndef VECTOR_H
#define	VECTOR_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct vector
 * @brief 1�����z��\����
 */
typedef struct {
    int size; /**< �T�C�Y */
    double* val; /**< �z��v�f */
} vector;

/**
 * @brief �T�C�Yn��1�����z��𓮓I�Ɋm��
 * @param[in] n �T�C�Y
 * @param[out] vec 1�����z��
 */
void vector_new(int n, vector* vec);

/**
 * @brief �m�ۂ���1�����z����J��
 * @param[in,out] vec �J������1�����z��
 */
void vector_delete(vector* vec);

/**
 * @brief 1�����z��vec2��vec1�ɃR�s�[
 * @param[out] vec1 �R�s�[��
 * @param[in] vec2 �R�s�[��
 * @retval 1 ����
 * @retval 0 ���s�ivec1��vec2�̃T�C�Y�s�����j
 */
int vector_copy(vector* vec1, const vector* vec2);

/**
 * @breif 1�����z��vec��format�ɏ]���ĕW���o�͂ɕ\��
 * @param[in] vec �o�͂���1�����z��
 * @param[in] format �o�͌`���iprinf�̑�P�����j
 */
void vector_print(const vector* vec, const char* format);

#endif	/* VECTOR_H */
