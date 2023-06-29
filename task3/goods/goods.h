#ifndef GOODS_H
#define GOODS_H

#include <stdio.h>
#include <string.h>

/*　構造体宣言 */
struct goods {
    char name[5]; // 品名
    int value; // 価格 
};

/*　関数プロトタイプ宣言 */
void registration(struct goods*, char*, int);
void print(struct goods);

#endif