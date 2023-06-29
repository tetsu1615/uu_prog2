#ifndef BANK_COMMON_H
#define BANK_COMMON_H

#include <stdio.h>
#include <stdlib.h>

/* 個人情報構造体の宣言 */
struct private_info {
    int amount; // 残高
    int password; // パスワード 
};

/* 個人情報構造体の外部変数の宣言 */
extern struct private_info info;

/* 関数プロトタイプ (bank_common.h) */
void insert_card(void);
void enter_password(void);
void show_amount(void);

#endif