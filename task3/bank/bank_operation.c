#include "bank_operation.h"

/********************
 * bank_operation.c
 ********************/

 /* �a���֐� */
void
deposit(void) {
	char buff[128];
	int dep;

	insert_card(); // �J�[�h�}��

	printf("�a������z����͂��Ă�������\n>>");
	rewind(stdin);
	while (fgets(buff, sizeof(buff), stdin) != NULL) {
		dep = atoi(buff);
		if (dep < 0) {
			printf("�s���ȋ��z�ł��D�ēx�C�a������z����͂��Ă�������\n>>");
		}
		else {
			info.amount += dep;
			break;
		}
	}

	show_amount(); // �c���\��
}

/* ���o�֐� */
void
withdraw(void) {
	char buff[128];
	int dep;

	insert_card(); // �J�[�h�}��
	enter_password(); // �p�X���[�h����

	printf("�����o�����z����͂��Ă�������\n>>");
	rewind(stdin);
	while (fgets(buff, sizeof(buff), stdin) != NULL) {
		dep = atoi(buff);
		if ((dep < 0) || (dep > info.amount)) {
			printf("�s���ȋ��z�ł��D�ēx�C�����o�����z����͂��Ă�������\n>>");
		}
		else {
			info.amount -= dep;
			break;
		}
	}
	show_amount(); // �c���\��
}

/* �c���Ɖ�֐� */
void
check(void) {
	insert_card(); // �J�[�h�}��
	enter_password(); // �p�X���[�h����
	show_amount(); // �c���\��
}