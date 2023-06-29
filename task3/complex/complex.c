#include "complex.h"

void
complex_number_print(struct complex_number a) {
    if (a.imag < 0) {
        printf("%f%fi", a.real, a.imag);
    }
    else {
        printf("%f+%fi", a.real, a.imag);
    }
}

struct complex_number
    complex_number_add(struct complex_number a, struct complex_number b) {
    struct complex_number result;

    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;

    return result;
}

struct complex_number
    complex_number_sub(struct complex_number a, struct complex_number b) {
    struct complex_number result;

    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;

    return result;
}

struct complex_number
    complex_number_mul(struct complex_number a, struct complex_number b) {
    struct complex_number result;

    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;

    return result;
}

struct complex_number
    complex_number_div(struct complex_number a, struct complex_number b) {
    struct complex_number result = { 0.0, 0.0 };
    double d;

    d = b.real * b.real + b.imag * b.imag;
    if (d == 0.0) {
        printf("divided by zero\n");
        return result;
    }

    result.real = (a.real * b.real + a.imag * b.imag) / d;
    result.imag = (-a.real * b.imag + a.imag * b.real) / d;

    return result;
}

struct complex_number
    complex_number_new(double real, double imag) {
    struct complex_number result;

    result.real = real;
    result.imag = imag;

    return result;
}

double
complex_number_real(struct complex_number a) {
    return a.real;
}

double
complex_number_imag(struct complex_number a) {
    return a.imag;
}

struct complex_number
    complex_number_conj(struct complex_number a) {
    struct complex_number result;

    result.real = a.real;
    result.imag = (-1) * a.imag;

    return result;
}

double
complex_number_abs(struct complex_number a) {
    return sqrt(pow(a.real, 2.0) + pow(a.imag, 2.0));
}

double
complex_number_arg(struct complex_number a) {
    return atan2(a.imag, a.real);
}

struct complex_number
    complex_number_polar(double abs, double arg) {
    struct complex_number result;

    result.real = (abs)*cos(arg);
    result.imag = (abs)*sin(arg);

    return result;
}

