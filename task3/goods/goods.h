#ifndef GOODS_H
#define GOODS_H

#include <stdio.h>
#include <string.h>

/*�@�\���̐錾 */
struct goods {
    char name[5]; // �i��
    int value; // ���i 
};

/*�@�֐��v���g�^�C�v�錾 */
void registration(struct goods*, char*, int);
void print(struct goods);

#endif