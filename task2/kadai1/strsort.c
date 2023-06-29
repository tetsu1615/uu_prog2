#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 20000 // �ő�̍s��
#define LINELENGTH 20	 // 1�s�̍ő啶����

/*
	int ReadLines(char *lines[], int numMax)

		�W�����͂���̓��͂��C��s�����I�Ɋm�ۂ����������Ɋi�[���C
	���̃A�h���X�𕶎���ւ̃|�C���^�z��ɕۑ�����D
	EOF(Ctrl+Z) �œ��͂��I������D

		lines   : ������ւ̃|�C���^�̔z��
	numMax  : �ő�̓ǂݍ��ݍs��

		�߂�l  : �ǂݍ��񂾍s��
*/
int ReadLines(char *lines[], int numMax)
{
	int cnt = 0;
	static char buf[LINELENGTH];

	while (cnt < numMax && gets(buf))
	{
		lines[cnt] = malloc(strlen(buf) + 1);
		if (lines[cnt] == NULL)
		{
			printf("Allocation error.\n");
			break;
		}
		strcpy(lines[cnt], buf);
		cnt++;
	}

	return cnt;
}

/*
	void PrintLines(char *line[], int num)

		�|�C���^�z��̎w���������W���o�͂ɕ\��

		lines   : ������ւ̃|�C���^�̔z��
	num     : �s���i�z����̗L���Ȓl�̐��j

		�߂�l  : �Ȃ�
*/
void PrintLines(char *lines[], int num)
{
	int i;
	for (i = 0; i < num; i++)
		printf("%s\n", lines[i]);
}

/*
	void Sort(char *line[], int num)

	�|�C���^�̔z����C�������Ƀ\�[�g

		lines   : ������ւ̃|�C���^�̔z��
	num     : �s���i�z����̗L���Ȓl�̐��j

		�߂�l  : �Ȃ�
*/
void Sort(char *lines[], int num)
{
	char *tmp;
	int i, j;
	for (i = 0; i < num - 1; i++)
	{
		for (j = num - 1; j > i; j--)
			if (strcmp(lines[j - 1], lines[j]) > 0)
			{
				tmp = lines[j - 1];
				lines[j - 1] = lines[j];
				lines[j] = tmp;
			}
	}
}

int main()
{
	int cnt;

	// ������ւ̃|�C���^�̔z��
	static char *lines[MAXLINES];

	cnt = ReadLines(lines, MAXLINES);
	printf("----- %d lines -----\n", cnt);
	Sort(lines, cnt);
	PrintLines(lines, cnt);

	free(*lines);

	return 0;
}