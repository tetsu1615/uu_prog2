#ifndef BANK_COMMON_H
#define BANK_COMMON_H

#include <stdio.h>
#include <stdlib.h>

/* �l���\���̂̐錾 */
struct private_info {
    int amount; // �c��
    int password; // �p�X���[�h 
};

/* �l���\���̂̊O���ϐ��̐錾 */
extern struct private_info info;

/* �֐��v���g�^�C�v (bank_common.h) */
void insert_card(void);
void enter_password(void);
void show_amount(void);

#endif