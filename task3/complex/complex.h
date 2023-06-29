#ifndef COMPLEX_H
#define	COMPLEX_H

#include <stdio.h>
#include <math.h>

/**
 * @struct complex_number
 * @breif •¡‘f”‚ğ•\Œ»‚·‚é\‘¢‘Ì
 */
struct complex_number {
    double real; /**< À”•” */
    double imag; /**< ‹•”•” */
};

/**
 * @brief •¡‘f”‚Ì•\¦
 * @param a •\¦‚·‚é•¡‘f”
 */
void complex_number_print(struct complex_number a);

/**
 * @breif •¡‘f”‚Ì‰ÁZ
 * @param a •¡‘f”
 * @param b •¡‘f”
 * @return a + b
 */
struct complex_number
    complex_number_add(struct complex_number a, struct complex_number b);

/**
 * @brief •¡‘f”‚ÌŒ¸Z
 * @param a •¡‘f”
 * @param b •¡‘f”
 * @return a - b
 */
struct complex_number
    complex_number_sub(struct complex_number a, struct complex_number b);

/**
 * @brief •¡‘f”‚ÌæZ
 * @param a •¡‘f”
 * @param b •¡‘f”
 * @return a * b
 */
struct complex_number
    complex_number_mul(struct complex_number a, struct complex_number b);

/**
 * @brief •¡‘f”‚ÌœZ
 * @param a •¡‘f”
 * @param b •¡‘f”
 * @return a / b
 */
struct complex_number
    complex_number_div(struct complex_number a, struct complex_number b);

/**
 * @breif •¡‘f”‚ÌÀ•”‚Æ‹••”‚ğ—^‚¦‚Ä•¡‘f”‚ğ•Ô‚·
 * @param real •¡‘f”‚ÌÀ•”
 * @param imag •¡‘f”‚Ì‹••”
 * @return (real) + (imag) i
 */
struct complex_number
    complex_number_new(double real, double imag);

/**
 * @biref •¡‘f”‚ÌÀ•”
 * @param a •¡‘f”
 * @return •¡‘f”a‚ÌÀ•” ( real )
 */
double
complex_number_real(struct complex_number a);

/**
 * @brief •¡‘f”‚Ì‹••”
 * @param a •¡‘f”
 * @return •¡‘f”a‚Ì‹••” ( imag )
 */
double
complex_number_imag(struct complex_number a);

/**
 * @brief •¡‘f”‚Ì‹¤–ğ
 * @param a •¡‘f”
 * @return Re{a} - Im{a} i
 */
struct complex_number
    complex_number_conj(struct complex_number a);

/**
 * @brief •¡‘f”‚Ìâ‘Î’l
 * @param a •¡‘f”
 * @retval |a|
 */
double
complex_number_abs(struct complex_number a);

/**
 * @breif •¡‘f”‚Ì•ÎŠp
 * @param a •¡‘f”
 * @return arctan(Im{a}/Re{a})
 */
double
complex_number_arg(struct complex_number a);

/**
 * @brief â‘Î’l‚Æ•ÎŠp‚ğ—^‚¦‚Ä•¡‘f”‚ğ•Ô‚·
 * @param abs â‘Î’l
 * @param arg •ÎŠp
 * @return (abs)*cos(arg) + (abs)*sin(arg) i
 */
struct complex_number
    complex_number_polar(double abs, double arg);

#endif	/* COMPLEX_H */

