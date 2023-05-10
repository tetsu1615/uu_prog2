#include <stdio.h>
#include <string.h>

void printAt(int t, char *str, char str_rev[])
{

	/*
	3-2:この関数の中身を作る
	*/
	int i;
	printf("文字の位置を入力してください> ");
	scanf("%d", &i);
	printf("ユーザの入力： %d\n", i);
	/*ユーザの入力が文字数を超えていた場合の処理*/
	// printf("文字数は%d文字\n", t);
	if (i > t)
	{
		printf("Error!入力された文字数を超えています\n");
	}
	else
	{
		/*それ以外の場合は指定された位置の文字を表示*/
		printf("ユーザが入力した文字列の場合: %c\n", str[i]);
		printf("反転した文字列の場合: %c\n", str_rev[i - 1]);
	}
}

int main(void)
{
	char input[20], *p_in, reverse[20], *p_rev;
	int len = 0; /*文字数を格納する変数*/

	printf("文字列を入力してください\n");
	scanf("%s", input);

	/*
	3-1:ここに入力された文字数を把握するための処理を追加
	*/
	len = strlen(input);

	printf("文字数は%d文字\n", len); /*文字数表示*/

	/*文字列の配列の先頭アドレスをポインタにコピー*/
	p_in = input;
	p_rev = reverse;

	/*
	3-1:ここに文字列反転の処理を作る
	*/
	p_in += len - 1; // p_inを文字列の末尾に移動
	while (len > 0)
	{
		*p_rev = *p_in; // 反転した文字をコピー
		p_rev++;				// ポインタを進める
		p_in--;					// ポインタを逆方向に進める
		len--;					// 文字数をデクリメント
	}
	*p_rev = '\0'; // 反転した文字列の終端を設定

	// 文字数を再度取得
	len = strlen(input);

	/*ユーザの入力と反転結果の表示*/
	printf("ユーザの入力: %s\n", input);
	printf("反転した出力: %s\n", reverse);

	/*ユーザが入力した位置の文字を表示する関数printAtへ*/
	printAt(len, p_in, reverse); /*ユーザが入力した文字列はポインタ，反転した文字列は配列を渡す*/

	return 0;
}