#include <stdio.h>

struct  complex_number {          /* 複素数を表現する構造体 */
    double	real;    /* 実数部 */
    double	imag;    /* 虚数部 */
};

/* 複素数の加算 */
struct complex_number
complex_number_add(struct complex_number a, struct complex_number b)
{
    struct complex_number result;

    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;

    return result;
}

/* 複素数の減算 */
struct complex_number
complex_number_sub(struct complex_number a, struct complex_number b)
{
    struct complex_number result;

    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;

    return result;
}

/* 複素数の乗算 */
struct complex_number
complex_number_mul(struct complex_number a, struct complex_number b)
{
    struct complex_number result;

    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;

    return result;
}

/* 複素数の除算 */
struct complex_number
complex_number_div(struct complex_number a, struct complex_number b)
{
    struct complex_number result = { 0.0, 0.0 };
    double d;

    d = b.real * b.real + b.imag * b.imag;
    if (d == 0.0) {
	printf("divided by zero\n");
	return result;
    }

    result.real = (a.real * b.real + a.imag * b.imag)/d;
    result.imag = (- a.real * b.imag + a.imag * b.real)/d;

    return result;
}

/* 複素数の表示 */
void
complex_number_print(struct complex_number a)
{
    if (a.imag < 0)
	printf("%f%fi", a.real, a.imag);
    else
	printf("%f+%fi", a.real, a.imag);
}

void
calc_test(struct complex_number a, struct complex_number b, char optype)
{
    struct complex_number c;

    switch (optype) {
    case '+':
	c = complex_number_add(a, b);
	break;
    case '-':
	c = complex_number_sub(a, b);
	break;
    case '*':
	c = complex_number_mul(a, b);
	break;
    case '/':
	c = complex_number_div(a, b);
	break;
    default:
	printf("unknown operation type %c\n", optype);
	return;
	break;
    }

    complex_number_print(a);
    printf(" %c ", optype);
    complex_number_print(b);
    printf(" = ");
    complex_number_print(c);
    printf("\n");
}

int
main(void)
{
    struct complex_number a, b;		/* 構造体complex_number型の変数の宣言 */

    a.real = 3.0; a.imag = 4.0;    	/* 変数aの値の設定 */
    b.real = 1.0; b.imag = 2.0;    	/* 変数bの値の設定 */

    /* 2つの複素数の四則演算結果を表示 */
    calc_test(a, b, '+');
    calc_test(a, b, '-');
    calc_test(a, b, '*');
    calc_test(a, b, '/');

    return 0;
}
