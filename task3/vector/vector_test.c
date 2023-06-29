#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(void) {
    int n;
    vector vec1, vec2;

    /* 1�����z��̃T�C�Y�ݒ� */
    n = 4;
    /* vec1�̗̈�m�� */
    vector_new(n, &vec1);
    /* �v�f�̑�� */
    vec1.val[0] = 0.2;
    vec1.val[1] = 1.3;
    vec1.val[2] = 2.5;
    vec1.val[3] = 3.6;
    /* vec1�̗v�f�̕\�� */
    printf("vec1 = ");
    vector_print(&vec1, "%f");
    /* vec2�̗̈�m�� */
    vector_new(n, &vec2);
    /* 1�����z��̗v�f�̃R�s�[ */
    if (vector_copy(&vec2, &vec1)) {
        /* vec2�̗v�f�̕\�� */
        printf("vec2 = ");
        vector_print(&vec2, "%f");
    }
    /* �̈�̊J�� */
    vector_delete(&vec1);
    vector_delete(&vec2);

    return EXIT_SUCCESS;
}
