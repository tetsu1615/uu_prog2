#include "bank_operation.h"

/********************
 * bank_operation.c
 ********************/

 /* 預入関数 */
void
deposit(void) {
	char buff[128];
	int dep;

	insert_card(); // カード挿入

	printf("預ける金額を入力してください\n>>");
	rewind(stdin);
	while (fgets(buff, sizeof(buff), stdin) != NULL) {
		dep = atoi(buff);
		if (dep < 0) {
			printf("不正な金額です．再度，預ける金額を入力してください\n>>");
		}
		else {
			info.amount += dep;
			break;
		}
	}

	show_amount(); // 残高表示
}

/* 引出関数 */
void
withdraw(void) {
	char buff[128];
	int dep;

	insert_card(); // カード挿入
	enter_password(); // パスワード入力

	printf("引き出す金額を入力してください\n>>");
	rewind(stdin);
	while (fgets(buff, sizeof(buff), stdin) != NULL) {
		dep = atoi(buff);
		if ((dep < 0) || (dep > info.amount)) {
			printf("不正な金額です．再度，引き出す金額を入力してください\n>>");
		}
		else {
			info.amount -= dep;
			break;
		}
	}
	show_amount(); // 残高表示
}

/* 残高照会関数 */
void
check(void) {
	insert_card(); // カード挿入
	enter_password(); // パスワード入力
	show_amount(); // 残高表示
}