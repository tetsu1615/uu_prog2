/* 単方向リストプログラム */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
// #include <crtdbg.h>

/********************* リスト処理部 *********************/

/* リストセル　構造体定義 */
typedef struct cell
{
	char string;
	struct cell *next;
} CELL, *PCELL;

/*
	PCELL ListCreate()
	リストヘッダの作成

	戻り値：作成したヘッダのアドレス
			作成に失敗した場合には NULL を返す
*/
PCELL ListCreate()
{
	return calloc(1, sizeof(CELL));
}

/*
	PCELL ListGetPrevPos(PCELL header, const char *str)
	header で指定されたリストから str で指定された文字列を
	格納したセルを検索し，その直前のセルを指すポインタを返す

	PCELL header   : リストヘッダ
	const char *str: 検索文字列
*/

PCELL ListGetPrevPos(PCELL header, const char *str)
{
	while (header->next)
	{
		if (strcmp(header->next->string, str) == 0)
		{
			return header;
		}
		header = header->next;
	}
	return NULL;
}

/*
	PCELL ListNext(PCELL pos)
	PCELL pos : 特定のセルを指すポインタ
	戻り値    ：pos の次のセルのポインタ
*/
PCELL ListNext(PCELL pos)
{
	return pos->next;
}

/*
	void ListPrintAll(PCELL header)
	リストのすべての要素を表示

	PCELL header : リストヘッダ
*/
void ListPrintAll(PCELL header)
{
	puts("-  addr  --  next  -:string");
	printf("[%08x][%08x]:HEADER\n", header, header->next);
	header = header->next;
	while (header)
	{
		printf("[%08x][%08x]:<%s>\n", header, header->next, header->string);
		header = header->next;
	}
	puts("------");
}

/*
	PCELL ListInsert(PCELL pos, const char *string)
	指定されたセルの次に，新しいセルの挿入する

	PCELL pos : 挿入位置のセルを指すポインタ
	char *string : 新セルに含める文字列

	戻り値： 新しく確保したセルのアドレス
			 メモリ確保に失敗した場合にはNULL
*/
PCELL ListInsert(PCELL pos, const char *string)
{
	PCELL pNewCell;
	pNewCell = (PCELL)calloc(1, sizeof(CELL)); // メモリ確保

	if (pNewCell != NULL)
	{
		// ここを実装する
		pNewCell->string = (char *)calloc(strlen(string) + 1, sizeof(char));
		// 新しいセルへの文字列をコピーおよび
		strcpy(pNewCell->string, string);
		// ポインタの付け替えを行う
		pNewCell->next = pos->next;
		pos->next = pNewCell;
	}
	return pNewCell;
}

/*
	void ListDelete(PCELL pos)
	セルの削除．pos の指すセルの次のセルを削除する．

	PCELL pos : 削除するセルの直前のセルを指すポインタ
*/
void ListDelete(PCELL pos)
{
	// ここを実装
	PCELL pTmpCell;
	pTmpCell = pos->next;
	pos->next = pos->next->next;
	free(pTmpCell->string);
	free(pTmpCell);
	_CrtDumpMemoryLeaks();
}

/*
	void ListDestory(PCELL header)
	リスト全体の削除

	PCELL header : ヘッダセルへのポインタ
*/
void ListDestroy(PCELL header)
{
	// ここを実装
	PCELL pTmpCell;
	while (header)
	{
		pTmpCell = header;
		header = header->next;
		free(pTmpCell->string);
		free(pTmpCell);
	}
	_CrtDumpMemoryLeaks();
}
/********************* main 関数 *********************/

#define BUFSIZE 20

int main()
{
	static char buf[BUFSIZE];
	PCELL header;

	header = ListCreate();

	for (;;)
	{
		printf(">>");
		gets(buf);
		switch (*buf)
		{
			/* リストの先頭に挿入 */
		case 'A':
		case 'a':
			printf("先頭に挿入する文字列を入力：");
			gets(buf);
			ListInsert(header, buf);
			break;
			/* 挿入 */
		case 'I':
		case 'i':
		{
			PCELL pos;
			printf("挿入位置の文字列を入力:");
			gets(buf);
			pos = ListGetPrevPos(header, buf);
			if (pos == NULL)
			{
				printf("\"%s\"は見つかりません\n", buf);
			}
			else
			{
				printf("挿入する文字列を入力:");
				gets(buf);
				ListInsert(ListNext(pos), buf);
			}
		}
		break;
		/* 削除 */
		case 'D':
		case 'd':
		{
			PCELL pos;
			printf("削除する文字列を入力:");
			gets(buf);
			pos = ListGetPrevPos(header, buf);
			if (pos == NULL)
			{
				printf("\"%s\"は見つかりません\n", buf);
			}
			else
			{
				ListDelete(pos);
			}
		}
		break;
		/* 全要素の表示 */
		case 'P':
		case 'p':
			ListPrintAll(header);
			break;
			/* プログラムの終了 */
		case 'E':
		case 'e':
			ListDestroy(header);
			exit(0);
			break;
		default:
			/* ヘルプメッセージの表示 */
			printf("(A)dd, (I)nsert, (D)elete, (P)rint, (E)xit\n");
		}
	}
	return 0;
}