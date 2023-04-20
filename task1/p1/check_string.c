#include <string.h>
#include <ctype.h>
#include <stdio.h>

void
check_string(char str[])
{
    char tmpbuf[256];    /* 十分な大きさにする(ここでは256) */

    /* strの文字列を tmpbufにコピー */
    strcpy(tmpbuf, str);

    /* それぞれの文字列の内容と長さを表示 */
    printf("original string = '%s' (len=%d)\n", str, strlen(str));
    printf("copy string = '%s' (len=%d)\n", tmpbuf, strlen(tmpbuf));

    /* 文字列の比較(ここでは同じはず) */
    if (strcmp(tmpbuf, str) == 0)
        printf("2 string is same\n");
    else
        printf("2 string is different\n");

    printf("\n");

    /* tmpbufの文字列の後ろに別の文字列を連結 */
    strcat(tmpbuf, ", far away");

    /* それぞれの文字列の内容と長さを表示 */
    /* (連結した分 tmpbuf側の文字列が長くなっている) */
    printf("original string = '%s' (len=%d)\n", str, strlen(str));
    printf("copy string = '%s' (len=%d)\n", tmpbuf, strlen(tmpbuf));

    /* 文字列の比較(ここでは異なるはず) */
    if (strcmp(tmpbuf, str) == 0)
        printf("2 string is same\n");
    else
        printf("2 string is different\n");
}

int
main(void)
{
    check_string("A Long time ago in a galaxy");

    return 0;
}