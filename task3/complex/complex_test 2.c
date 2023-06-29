#include <stdlib.h>
#include "complex.h"

int
main(void) {
    struct complex_number z;
    double abs, arg;

    /* “K“–‚È•¡‘f”‚ğİ’è */
    z = complex_number_new(3.0, 4.0);

    /* z‚ğ•\¦ */
    printf("z = ");
    complex_number_print(z);
    printf("\n");


    /* z‚Ì•¡‘f‹¤–ğ‚ğ•\¦ */
    printf("conj(z) = ");
    complex_number_print(complex_number_conj(z));
    printf("\n");

    /* z‚Ìâ‘Î’l‚ğ•\¦ */
    abs = complex_number_abs(z);
    printf("abs(z) = %f\n", abs);

    /* z‚Ì•ÎŠp‚ğ•\¦ */
    arg = complex_number_arg(z);
    printf("arg(z) = %f\n", arg);

    /* abs‚Æarg‚ğ—^‚¦‚Ä•¡‘f”‚ğ•\¦ */
    printf("polar(abs,arg) = ");
    complex_number_print(complex_number_polar(abs, arg));
    printf("\n");

    return EXIT_SUCCESS;
}