#include "vector.h"

void vector_new(int n, vector* vec) {
    if (n <= 0) {
        fprintf(stderr, "allocation failure in vector_new()\n");
        exit(EXIT_FAILURE);
    }
    else {
        vec->val = (double*)malloc(n * sizeof(double));
        if (vec->val == NULL) {
            fprintf(stderr, "allocation failure in vector_new()\n");
            exit(EXIT_FAILURE);
        }
        vec->size = n;
    }
}

void vector_delete(vector* vec) {
    free(vec->val);
}

int vector_copy(vector* vec1, const vector* vec2) {
    int i;

    if (vec1->size != vec2->size) {
        return 0;
    }
    for (i = 0; i < vec1->size; ++i) {
        vec1->val[i] = vec2->val[i];
    }
    return 1;
}

void vector_print(const vector* vec, const char* format) {
    int i;
    printf("[");
    for (i = 0; i < vec->size; ++i) {
        printf(format, vec->val[i]);
        if (i < vec->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}