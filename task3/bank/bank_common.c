#include "bank_common.h"

/*****************
 * bank_common.c
 *****************/

 /* �J�[�h�}���֐� */
void
insert_card(void) {
    // �ύX�Ȃ�
    printf("�J�[�h���}������܂���\n");
}

/* �p�X���[�h���͊֐� */
void
enter_password(void) {
// �ύX�Ȃ�
	char pass[5];

	printf("�p�X���[�h����͂��Ă�����\n>>");
	rewind(stdin);
	while (fgets(pass, sizeof(pass), stdin) != NULL) {
		if (info.password != atoi(pass)) {
			printf("�p�X���[�h���Ԉ���Ă��܂��D������x���͂��Ă�������\n>>");
			rewind(stdin);
		}
		else {
			break;
		}
	}
	printf("�F�؂ɐ������܂���\n");
}

/* �c���\���֐� */
void
show_amount(void) {
    // �ύX�Ȃ�
	printf("���݂̎c���� %d �~�ł�\n", info.amount);
}