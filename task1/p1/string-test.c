#include <ctype.h>
#include <stdio.h>

int
string_length(char str[])
{
    int len = 0;

    while (str[len] != '\0')
	len++;

    return len;
}

void
string_toupper(char dst[], char src[])
{
    int i = 0;

    while (src[i] != '\0') {
	dst[i] = toupper(src[i]);
	i++;
    }

    dst[i] = '\0';
}

void
check_string(char str[])
{
    char tmpbuf[256];

    printf("check '%s'\n", str);
    printf("length is %d\n", string_length(str));

    string_toupper(tmpbuf, str);
    printf("%s\n", tmpbuf);

    printf("\n");
}

int
main(void)
{
    check_string("A quick brown fox jumps over the lazy dog.");

    return 0;
}
