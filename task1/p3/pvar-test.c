#include <stdio.h>

int
main(void)
{
    int a = 314;
    char s[] = "abc";
    int *pa;
    char *ps;

    pa = &a;
    ps = &s[1];

    printf("pa=%p\n", pa);
    printf("ps=%p\n", ps);

    return 0;
}
