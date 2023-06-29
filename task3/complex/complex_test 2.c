#include <stdlib.h>
#include "complex.h"

int
main(void) {
    struct complex_number z;
    double abs, arg;

    /* �K���ȕ��f����ݒ� */
    z = complex_number_new(3.0, 4.0);

    /* z��\�� */
    printf("z = ");
    complex_number_print(z);
    printf("\n");


    /* z�̕��f������\�� */
    printf("conj(z) = ");
    complex_number_print(complex_number_conj(z));
    printf("\n");

    /* z�̐�Βl��\�� */
    abs = complex_number_abs(z);
    printf("abs(z) = %f\n", abs);

    /* z�̕Ίp��\�� */
    arg = complex_number_arg(z);
    printf("arg(z) = %f\n", arg);

    /* abs��arg��^���ĕ��f����\�� */
    printf("polar(abs,arg) = ");
    complex_number_print(complex_number_polar(abs, arg));
    printf("\n");

    return EXIT_SUCCESS;
}