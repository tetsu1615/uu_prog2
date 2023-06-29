#ifndef COMPLEX_H
#define	COMPLEX_H

#include <stdio.h>
#include <math.h>

/**
 * @struct complex_number
 * @breif ���f����\������\����
 */
struct complex_number {
    double real; /**< ������ */
    double imag; /**< ������ */
};

/**
 * @brief ���f���̕\��
 * @param a �\�����镡�f��
 */
void complex_number_print(struct complex_number a);

/**
 * @breif ���f���̉��Z
 * @param a ���f��
 * @param b ���f��
 * @return a + b
 */
struct complex_number
    complex_number_add(struct complex_number a, struct complex_number b);

/**
 * @brief ���f���̌��Z
 * @param a ���f��
 * @param b ���f��
 * @return a - b
 */
struct complex_number
    complex_number_sub(struct complex_number a, struct complex_number b);

/**
 * @brief ���f���̏�Z
 * @param a ���f��
 * @param b ���f��
 * @return a * b
 */
struct complex_number
    complex_number_mul(struct complex_number a, struct complex_number b);

/**
 * @brief ���f���̏��Z
 * @param a ���f��
 * @param b ���f��
 * @return a / b
 */
struct complex_number
    complex_number_div(struct complex_number a, struct complex_number b);

/**
 * @breif ���f���̎����Ƌ�����^���ĕ��f����Ԃ�
 * @param real ���f���̎���
 * @param imag ���f���̋���
 * @return (real) + (imag) i
 */
struct complex_number
    complex_number_new(double real, double imag);

/**
 * @biref ���f���̎���
 * @param a ���f��
 * @return ���f��a�̎��� ( real )
 */
double
complex_number_real(struct complex_number a);

/**
 * @brief ���f���̋���
 * @param a ���f��
 * @return ���f��a�̋��� ( imag )
 */
double
complex_number_imag(struct complex_number a);

/**
 * @brief ���f���̋���
 * @param a ���f��
 * @return Re{a} - Im{a} i
 */
struct complex_number
    complex_number_conj(struct complex_number a);

/**
 * @brief ���f���̐�Βl
 * @param a ���f��
 * @retval |a|
 */
double
complex_number_abs(struct complex_number a);

/**
 * @breif ���f���̕Ίp
 * @param a ���f��
 * @return arctan(Im{a}/Re{a})
 */
double
complex_number_arg(struct complex_number a);

/**
 * @brief ��Βl�ƕΊp��^���ĕ��f����Ԃ�
 * @param abs ��Βl
 * @param arg �Ίp
 * @return (abs)*cos(arg) + (abs)*sin(arg) i
 */
struct complex_number
    complex_number_polar(double abs, double arg);

#endif	/* COMPLEX_H */

