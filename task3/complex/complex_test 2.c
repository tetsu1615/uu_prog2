#include <stdlib.h>
#include "complex.h"

int
main(void) {
    struct complex_number z;
    double abs, arg;

    /* 適当な複素数を設定 */
    z = complex_number_new(3.0, 4.0);

    /* zを表示 */
    printf("z = ");
    complex_number_print(z);
    printf("\n");


    /* zの複素共役を表示 */
    printf("conj(z) = ");
    complex_number_print(complex_number_conj(z));
    printf("\n");

    /* zの絶対値を表示 */
    abs = complex_number_abs(z);
    printf("abs(z) = %f\n", abs);

    /* zの偏角を表示 */
    arg = complex_number_arg(z);
    printf("arg(z) = %f\n", arg);

    /* absとargを与えて複素数を表示 */
    printf("polar(abs,arg) = ");
    complex_number_print(complex_number_polar(abs, arg));
    printf("\n");

    return EXIT_SUCCESS;
}