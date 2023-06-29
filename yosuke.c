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
	// �J�E���^��錾
	int i, j;
	// ������|�C���^�̔��p
	char *buf;
	// �\�[�g�ς݂̕�����̏ꏊ���C���N�������g
	for (i = 0; i < num - 1; i++)
	{
		// �Ō�̕����񂩂�܂Ń\�[�g�ς݂̕�����̎�O�܂Ńf�N�������g
		for (j = num - 1; j > i; j--)
		{
			// �ׂ荇��������̕����R�[�h���r
			if (strcmp(lines[j - 1], lines[j]) > 0)
			{
				// lines[j]��buf�ɑ��
				buf = lines[j];
				// lines[j]��lines[j - 1]����
				lines[j] = lines[j - 1];
				// lines[j - 1]��buf����
				lines[j - 1] = buf;
			}
		}
	}
}

void Freelines(char *lines[], int num)
{
	int i;
	for (i = 0; i < num; i++)
		free(lines[i]);
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
	Freelines(lines, cnt);

	return 0;
}