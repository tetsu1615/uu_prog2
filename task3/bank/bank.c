#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bank_common.h"
#include "bank_operation.h"

/* �l���\���̂̊O���ϐ��̒�` */
struct private_info info = { 10000, 1234 };

/* ���C���֐� */
int
main(void) {
	char buff[2];

	printf("�����p���e��I�����Ă������� [ �a��:d, ���o:w, �Ɖ�:s, �I��:f ]\n>>");
	while (fgets(buff, sizeof(buff), stdin) != NULL) {
		if (strcmp(buff, "d") == 0) {
			deposit(); // �a��
		}
		else if (strcmp(buff, "w") == 0) {
			withdraw(); // ���o
		}
		else if (strcmp(buff, "s") == 0) {
			check(); // �Ɖ�
		}
		else if (strcmp(buff, "f") == 0) {
			break;
		}
		printf("�����p���e��I�����Ă������� [ �a��:d, ���o:w, �Ɖ�:s, �I��:f ]\n>>");
		rewind(stdin);
	}
	return EXIT_SUCCESS;
}

