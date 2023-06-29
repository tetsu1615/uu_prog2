#include "matrix.h"

void matrix_new(int m, int n, matrix *mat)
{
    int i;

    if ((m <= 0) || (n <= 0))
    {
        fprintf(stderr, "allocation failure in matrix_new()\n");
        exit(EXIT_FAILURE);
    }
    mat->val = (double **)malloc(m * sizeof(double *));
    if (mat->val == NULL)
    { /* —ÌˆæŠ„“–‚ÉŽ¸”s‚µ‚½‚ç */
        fprintf(stderr, "allocation failure in matrix_new()\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < m; ++i)
    {
        mat->val[i] = (double *)malloc(n * sizeof(double));
        if (mat->val[i] == NULL)
        { /* —ÌˆæŠ„“–‚ÉŽ¸”s‚µ‚½‚ç */
            while (--i >= 0)
            {
                free(mat->val[i]); /* —ÌˆæŠJ•ú */
            }
            free(mat->val);
            fprintf(stderr, "allocation failure in matrix_new()\n");
            exit(EXIT_FAILURE);
        }
    }
    mat->size1 = m;
    mat->size2 = n;
}

void matrix_delete(matrix *mat)
{
    int i;
    for (i = 0; i < mat->size1; ++i)
    {
        free(mat->val[i]);
    }
    free(mat->val);
    mat->size1 = mat->size2 = 0;
}

int matrix_copy(matrix *mat1, const matrix *mat2)
{
    int i, j;
    if ((mat1->size1 != mat2->size1) || (mat2->size2 != mat2->size2))
    {
        return 0;
    }
    for (i = 0; i < mat1->size1; ++i)
    {
        for (j = 0; j < mat1->size2; ++j)
        {
            mat1->val[i][j] = mat2->val[i][j];
        }
    }
    return 1;
}

void matrix_print(const matrix *mat, const char *format)
{
    int i, j;
    printf("[");
    for (i = 0; i < mat->size1; ++i)
    {
        for (j = 0; j < mat->size2; ++j)
        {
            printf(format, mat->val[i][j]);
            if (j < mat->size2 - 1)
            {
                printf(", ");
            }
        }
        if (i == mat->size1 - 1)
        {
            printf("]");
        }
        printf("\n");
    }
}