#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct matrix
 * @brief 2�����z��\����
 */
typedef struct
{
    int size1;    /**< �s�� */
    int size2;    /**< �� */
    double **val; /**< �z��v�f */
} matrix;

/**
 * @brief m�~n��2�����z��𓮓I�Ɋm��
 * @param[in] m �s��
 * @param[in] n ��
 * @param[out] mat 2�����z��
 */
void matrix_new(int m, int n, matrix *mat);

/**
 * @brief �m�ۂ���2�����z����J��
 * @param[in,out] mat �J������2�����z��
 */
void matrix_delete(matrix *mat);

/**
 * @brief 2�����z��mat2��mat1�ɃR�s�[
 * @param[out] mat1 �R�s�[��
 * @param[in] mat2 �R�s�[��
 * @retval 1 ����
 * @retval 0 ���s�imat1��mat2�̃T�C�Y�s�����j
 */
int matrix_copy(matrix *mat1, const matrix *mat2);

/**
 * @brief 2�����z��mat��format�ɏ]���ĕW���o�͂ɕ\��
 * @param[in] mat �o�͂���2�����z��
 * @param[in] format�o�͌`���iprinf�̑�1�����j
 */
void matrix_print(const matrix *mat, const char *format);

#endif /* MATRIX_H */
