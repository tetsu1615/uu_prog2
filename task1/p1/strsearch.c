#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRLEN 256 /* 入力文字列の最大長 */

/*
 *	search_string:
 *	文字列 'str'中に含まれる文字列 'pat'を探す
 *	大文字小文字を区別しない。
 *	文字列が含まれていればその場所を返す (先頭を0として何文字目か)
 *	含まれていなければ -1を返す
 *
 */
int search_string(char str[], char pat[])
{
    int i, j, k;

    /* 文字列の大文字を小文字に変換 */
    i = 0;
    while (str[i] != '\0')
    {
        str[i] = tolower(str[i]);
        i++;
    }
    i = 0;
    while (pat[i] != '\0')
    {
        pat[i] = tolower(pat[i]);
        i++;
    }

    /* 文字列検索 */
    i = 0;
    while (str[i] != '\0')
    {
        /* 文字列の先頭から順に文字列を比較 */
        j = 0;
        while (pat[j] != '\0')
        {
            if (str[i + j] != pat[j])
            {
                break;
            }
            j++;
        }
        /* 一致した文字数とpatの文字数が一致したら文字列が含まれているので、その位置を返す */
        if (pat[j] == '\0')
        {
            return i;
        }
        i++;
    }
    return -1;
}

int main(void)
{
    int pos;             /* 文字列検索の現在位置 */
    int i;               /* ループカウンタ */
    char str[MAXSTRLEN]; /* 文字列入力用(被検索文字列) */
    char pat[MAXSTRLEN]; /* 文字列入力用(検索文字列) */

    /* 2つの文字列を入力 */
    printf("input string = ");
    gets(str);
    printf("input pattern = ");
    gets(pat);

    /* 入力した2つの文字列を表示 */
    printf("string=\"%s\"\n", str);
    printf("pattern=\"%s\"\n", pat);

    /* 文字列検索 */
    pos = 0;
    int count = 0; // 見つかった回数を記録 [オプション課題]
    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    while (pos < i)
    {
        int ret;
        ret = search_string(&str[pos], pat);

        if (ret < 0) /* -1が返ってきたらループを抜ける */
            break;
        else
            count++;

        /* 文字列一致個所を発見(strの posからの相対位置が返る) */
        /* strの先頭からの位置は 'pos + ret'になるのでその値を表示する */
        printf("found at %d\n", pos + ret);

        pos += ret + 1; /* 検索位置を進める */
    }
    /* 見つかった回数を出力 [オプション課題] */
    printf("\nfound %d time(s)\n", count);

    return 0;
}
