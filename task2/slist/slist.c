/* �P�������X�g�v���O���� */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <crtdbg.h>


/********************* ���X�g������ *********************/

/* ���X�g�Z���@�\���̒�` */
typedef struct cell {
	char string[8];
	struct cell *next;
} CELL, *PCELL;

/*
	PCELL ListCreate()
	���X�g�w�b�_�̍쐬

	�߂�l�F�쐬�����w�b�_�̃A�h���X
	        �쐬�Ɏ��s�����ꍇ�ɂ� NULL ��Ԃ�
*/
PCELL ListCreate()
{
	return calloc(1, sizeof(CELL));
}

/*
	PCELL ListGetPrevPos(PCELL header, const char *str)
	header �Ŏw�肳�ꂽ���X�g���� str �Ŏw�肳�ꂽ�������
	�i�[�����Z�����������C���̒��O�̃Z�����w���|�C���^��Ԃ�

	PCELL header   : ���X�g�w�b�_
	const char *str: ����������
*/

PCELL ListGetPrevPos(PCELL header, const char *str)
{
	while (header->next) {
		if (strcmp(header->next->string, str) == 0) {
			return header;
		}
		header = header->next;
	}
	return NULL;
}

/*
	PCELL ListNext(PCELL pos)
	PCELL pos : ����̃Z�����w���|�C���^
	�߂�l    �Fpos �̎��̃Z���̃|�C���^
*/
PCELL ListNext(PCELL pos)
{
	return pos->next;
}

/*
	void ListPrintAll(PCELL header)
	���X�g�̂��ׂĂ̗v�f��\��

	PCELL header : ���X�g�w�b�_
*/
void ListPrintAll(PCELL header)
{
	puts("-  addr  --  next  -:string");
	printf("[%08x][%08x]:HEADER\n", header, header->next);
	header = header->next;
	while (header) {
		printf("[%08x][%08x]:<%s>\n", header, header->next, header->string);
		header = header->next;
	}
	puts("------");
}


/*
	PCELL ListInsert(PCELL pos, const char *string)
	�w�肳�ꂽ�Z���̎��ɁC�V�����Z���̑}������

	PCELL pos : �}���ʒu�̃Z�����w���|�C���^
	char *string : �V�Z���Ɋ܂߂镶����

	�߂�l�F �V�����m�ۂ����Z���̃A�h���X
	         �������m�ۂɎ��s�����ꍇ�ɂ�NULL
*/
PCELL ListInsert(PCELL pos, const char *string)
{
	PCELL pNewCell;
	pNewCell = calloc(1, sizeof(CELL));

	if (pNewCell != NULL) {
		// ��������������
		// �V�����Z���ւ̕�������R�s�[�����
		// �|�C���^�̕t���ւ����s��
	}
	return pNewCell;
}

/*
	void ListDelete(PCELL pos)
	�Z���̍폜�Dpos �̎w���Z���̎��̃Z�����폜����D

	PCELL pos : �폜����Z���̒��O�̃Z�����w���|�C���^
*/
void ListDelete(PCELL pos)
{
	// ����������
}

/*
	void ListDestory(PCELL header)
	���X�g�S�̂̍폜

	PCELL header : �w�b�_�Z���ւ̃|�C���^
*/
void ListDestroy(PCELL header)
{
	// ����������
}
/********************* main �֐� *********************/

#define BUFSIZE 20

int main()
{
	static char buf[BUFSIZE];
	PCELL header;

	header = ListCreate();

	for (;;) {
		printf(">>");
		gets(buf);
		switch (*buf) {
		/* ���X�g�̐擪�ɑ}�� */
		case 'A': case 'a':
			printf("�擪�ɑ}�����镶�������́F");
			gets(buf);
			ListInsert(header, buf);
			break;
		/* �}�� */
		case 'I': case 'i':
			{
				PCELL pos;
				printf("�}���ʒu�̕���������:");
				gets(buf);
				pos = ListGetPrevPos(header, buf);
				if (pos == NULL) {
					printf("\"%s\"�͌�����܂���\n", buf);
				} else {
					printf("�}�����镶��������:");	gets(buf);
					ListInsert(ListNext(pos), buf);
				}
			}
			break;
		/* �폜 */
		case 'D': case 'd':
			{
				PCELL pos;
				printf("�폜���镶��������:");
				gets(buf);
				pos = ListGetPrevPos(header, buf);
				if (pos == NULL) {
					printf("\"%s\"�͌�����܂���\n", buf);
				} else {
					ListDelete(pos);
				}
			}
			break;
		/* �S�v�f�̕\�� */
		case 'P': case 'p':
			ListPrintAll(header);
			break;
		/* �v���O�����̏I�� */
		case 'E': case 'e':
			ListDestroy(header);
			exit(0);
			break;
		default:
		/* �w���v���b�Z�[�W�̕\�� */
			printf("(A)dd, (I)nsert, (D)elete, (P)rint, (E)xit\n");
		}
	}
	return 0;
}
