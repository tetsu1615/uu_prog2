#include <stdio.h>

int
main(void)
{
    int a = 314;
    int *pa;

    pa = &a;

    printf("before write (a=%d)\n", a);

    *pa = 141;

    printf("after write (a=%d)\n", a);

    return 0;
}
