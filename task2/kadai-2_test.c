/* 単方向リストプログラム */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <crtdbg.h>

/********************* リスト処理部 *********************/

/* リストセル　構造体定義 */
typedef struct cell
{
	char string[8];
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
	pNewCell = calloc(1, sizeof(CELL));

	if (pNewCell != NULL)
	{
		// ここを実装する
		// 新しいセルへの文字列をコピーおよび
		// ポインタの付け替えを行う
		strcpy(pNewCell->string, string);
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
	// pos の次のセルを削除する
	PCELL pDelCell;
	pDelCell = pos->next;
	pos->next = pos->next->next;
	free(pDelCell);
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
	PCELL pDesCell;
	while (header)
	{
		pDesCell = header;
		header = header->next;
		free(pDesCell);
		_CrtDumpMemoryLeaks();
	}
}
/********************* main 関数 *********************/

// テスト用メイン関数
int main()
{
	PCELL header;

	header = ListCreate(); // リストの構築

	ListInsert(header, "panda"); // 要素の先頭への挿入
	ListInsert(header, "hippo");
	ListInsert(header, "shark");
	ListInsert(header, "koala");
	ListInsert(header, "giraff");
	ListInsert(header, "crane");

	ListPrintAll(header); // 表示

	// 挿入のテスト
	ListInsert(ListNext(ListGetPrevPos(header, "shark")), "walrus");

	// 削除のテスト
	ListDelete(ListGetPrevPos(header, "shark"));
	ListDelete(header);

	ListPrintAll(header); // 表示

	ListDestroy(header);
	// メモリリーク情報の表示
	_CrtDumpMemoryLeaks();
}