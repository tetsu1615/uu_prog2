#include "bank_common.h"

/*****************
 * bank_common.c
 *****************/

 /* カード挿入関数 */
void
insert_card(void) {
    // 変更なし
    printf("カードが挿入されました\n");
}

/* パスワード入力関数 */
void
enter_password(void) {
// 変更なし
	char pass[5];

	printf("パスワードを入力してださい\n>>");
	rewind(stdin);
	while (fgets(pass, sizeof(pass), stdin) != NULL) {
		if (info.password != atoi(pass)) {
			printf("パスワードが間違っています．もう一度入力してください\n>>");
			rewind(stdin);
		}
		else {
			break;
		}
	}
	printf("認証に成功しました\n");
}

/* 残高表示関数 */
void
show_amount(void) {
    // 変更なし
	printf("現在の残高は %d 円です\n", info.amount);
}