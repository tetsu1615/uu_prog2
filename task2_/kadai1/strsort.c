#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 20000 // 最大の行数
#define LINELENGTH 20	 // 1行の最大文字数

/*
	int ReadLines(char *lines[], int numMax)

		標準入力からの入力を，一行ずつ動的に確保したメモリに格納し，
	そのアドレスを文字列へのポインタ配列に保存する．
	EOF(Ctrl+Z) で入力を終了する．

		lines   : 文字列へのポインタの配列
	numMax  : 最大の読み込み行数

		戻り値  : 読み込んだ行数
*/
int ReadLines(char *lines[], int numMax)
{
	int cnt = 0;
	static char buf[LINELENGTH];

	while (cnt < numMax && gets(buf))
	{
		lines[cnt] = malloc(strlen(buf) + 1);
		if (lines[cnt] == NULL)
		{
			printf("Allocation error.\n");
			break;
		}
		strcpy(lines[cnt], buf);
		cnt++;
	}

	return cnt;
}

/*
	void PrintLines(char *line[], int num)

		ポインタ配列の指す文字列を標準出力に表示

		lines   : 文字列へのポインタの配列
	num     : 行数（配列内の有効な値の数）

		戻り値  : なし
*/
void PrintLines(char *lines[], int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("%s\n", lines[i]);
}

/*
	void Sort(char *line[], int num)

	ポインタの配列を，辞書順にソート

		lines   : 文字列へのポインタの配列
	num     : 行数（配列内の有効な値の数）

		戻り値  : なし
*/
void Sort(char *lines[], int num)
{
	char *tmp;
	int i, j;
	for (i = 0; i < num - 1; i++)
	{
		for (j = num - 1; j > i; j--)
			if (strcmp(lines[j - 1], lines[j]) > 0)
			{
				tmp = lines[j - 1];
				lines[j - 1] = lines[j];
				lines[j] = tmp;
			}
	}
}

int main()
{
	int cnt;

	// 文字列へのポインタの配列
	static char *lines[MAXLINES];

	cnt = ReadLines(lines, MAXLINES);
	printf("----- %d lines -----\n", cnt);
	Sort(lines, cnt);
	PrintLines(lines, cnt);

	free(*lines);

	return 0;
}