#include <stdio.h>

int
main(void)
{
    int a = 314;
    int *pa;
    int **ppa;

    pa = &a;
    ppa = &pa;

    printf("before write (a=%d)\n", a);

    **ppa = 141;

    printf("after write (a=%d)\n", a);

    return 0;
}
