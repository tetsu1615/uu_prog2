/*
 * rat-num.c
 * rational number calculation program
 */
#include <stdio.h>

/* 有理数(分数)を表現する構造体 */
typedef struct rational_number
{
    int numer; /* 分子 (numerator) */
    int denom; /* 分母 (denominator) */
} rational_number;

/* 有理数(分数)の加算 */
/* 2つの引数で与えられた分数の和を求めて返す */
rational_number
rational_number_add(rational_number a, rational_number b)
{
    rational_number result;

    result.numer = a.numer * b.denom + b.numer * a.denom;
    result.denom = a.denom * b.denom;

    return result;
}

/* 有理数(分数)の減算 */
/* 2つの引数で与えられた分数の差を求めて返す */
rational_number
rational_number_sub(rational_number a, rational_number b)
{
    rational_number result;

    result.numer = a.numer * b.denom - b.numer * a.denom;
    result.denom = a.denom * b.denom;

    return result;
}

/* 有理数(分数)の乗算 */
/* 2つの引数で与えられた分数の積を求めて返す */
rational_number
rational_number_mul(rational_number a, rational_number b)
{
    rational_number result;

    result.numer = a.numer * b.numer;
    result.denom = a.denom * b.denom;

    return result;
}

/* 有理数(分数)の除算 */
/* 2つの引数で与えられた分数の商を求めて返す */
rational_number
rational_number_div(rational_number a, rational_number b)
{
    rational_number result;

    result.numer = a.numer * b.denom;
    result.denom = a.denom * b.numer;

    return result;
}

/* ユークリッドの互除法 */
int gcd(int a, int b)
{
    int i;

    i = a % b;
    if (i == 0)
    {
        return b;
    }
    else
    {
        a = b;
        b = i;
        return gcd(a, b);
    }
}

/* 有理数(分数)の既約化 */
/* 引数で与えられた分数の既約分数を求めて返す */
rational_number
rational_number_reduced(rational_number a)
{
    int i = gcd(a.numer, a.denom);

    if (i != 0)
    {
        a.numer = a.numer / i;
        a.denom = a.denom / i;
    }

    if (a.denom < 0)
    {
        a.numer = (-1) * a.numer;
        a.denom = (-1) * a.denom;
    }

    return a;
}

/* 有理数(分数)の表示 */
void rational_number_print(rational_number r)
{
    /*
     * "[ 分子/分母 ]" の形式で表示
     *
     * ただし、
     * 0のときはそのまま "0"と表示
     * 1のときはそのまま "1"と表示
     */

    r = rational_number_reduced(r); /* 表示前に既約化 */

    if (r.numer == 0)
        printf("0");
    else if (r.numer == 1 && r.denom == 1)
        printf("1");
    else
        printf("[ %d/%d ]", r.numer, r.denom);
}

/* ここから先は動作テスト用の関数 */

void test_rational_number_calc(rational_number a, rational_number b, char optype)
{
    rational_number c;

    switch (optype)
    {
    case '+':
        c = rational_number_add(a, b);
        break;
    case '-':
        c = rational_number_sub(a, b);
        break;
    case '*':
        c = rational_number_mul(a, b);
        break;
    case '/':
        c = rational_number_div(a, b);
        break;
    default:
        printf("unknown operation type %c\n", optype);
        return;
        break;
    }

    /* 計算内容の表示 */
    rational_number_print(a);
    printf(" %c ", optype);
    rational_number_print(b);
    printf(" = ");
    rational_number_print(c);
    printf("\n");
}

int main(void)
{
    rational_number a, b; /* 構造体 rational_number型の変数の宣言 */

    /* キーボードから4つの数を入力 */
    printf("input number (a.numer) = ");
    scanf("%d", &a.numer);
    printf("input number (a.denom) = ");
    scanf("%d", &a.denom);
    printf("input number (b.numer) = ");
    scanf("%d", &b.numer);
    printf("input number (b.denom) = ");
    scanf("%d", &b.denom);

    /* 2つの有理数(分数)の四則演算結果を表示 */
    test_rational_number_calc(a, b, '+');
    test_rational_number_calc(a, b, '-');
    test_rational_number_calc(a, b, '*');
    test_rational_number_calc(a, b, '/');

    return 0;
}
