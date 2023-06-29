#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bank_common.h"
#include "bank_operation.h"

/* 個人情報構造体の外部変数の定義 */
struct private_info info = { 10000, 1234 };

/* メイン関数 */
int
main(void) {
	char buff[2];

	printf("ご利用内容を選択してください [ 預入:d, 引出:w, 照会:s, 終了:f ]\n>>");
	while (fgets(buff, sizeof(buff), stdin) != NULL) {
		if (strcmp(buff, "d") == 0) {
			deposit(); // 預入
		}
		else if (strcmp(buff, "w") == 0) {
			withdraw(); // 引出
		}
		else if (strcmp(buff, "s") == 0) {
			check(); // 照会
		}
		else if (strcmp(buff, "f") == 0) {
			break;
		}
		printf("ご利用内容を選択してください [ 預入:d, 引出:w, 照会:s, 終了:f ]\n>>");
		rewind(stdin);
	}
	return EXIT_SUCCESS;
}

