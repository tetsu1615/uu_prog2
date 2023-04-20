#include <ctype.h>
#include <stdio.h>

void
check_char(char c)
{
    printf("check '%c'\n", c);

    if (isalpha(c)) {
	printf("'%c' is alphabet\n", c);
    }
    if (isdigit(c)) {
	printf("'%c' is digit char\n", c);
    }
    if (isupper(c)) {
	printf("'%c' is uppercase char\n", c);
	printf("lowercase of '%c' is '%c'\n", c, tolower(c));
    }
    if (islower(c)) {
	printf("'%c' is lowercase char\n", c);
	printf("uppercase of '%c' is '%c'\n", c, toupper(c));
    }
    if (isspace(c)) {
	printf("'%c' is white space\n", c);
    }

    printf("\n");
}

int
main(void)
{
    int c;

    printf("input character=");
    c = getchar();
    check_char(c);

    return 0;
}
