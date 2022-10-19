#include <stdio.h>
#include <errors.h>
#include <stdlib.h>
#include "work_matrix.h"
#include "errors.h"

int create_matrix(FILE *f, double ***a, size_t *n, size_t *m, size_t *k)
{
    int error = OK;

    if (fscanf(f, "%zu %zu %zu", n, m, k) != SCANF_OK)
        return NEGATIVE_SCANF;

    *a = allocated_matrix(*n, *m);

    if (!a)
        return NEGATIVE_ALLOC;

    error = read_matrix(f, *a, *n, *m, *k);
    return error;
}

double** allocated_matrix(size_t n, size_t m)
{
    double **data = malloc(n * sizeof(double*) + n * m * sizeof(double));

    if (!data)
        return NULL;

    for (size_t i = 0; i < n; i++)
        data[i] = (double*)((char *) data + n * sizeof(double*) + i * m * sizeof(double));

    return data;
}

// void matrix_free(double **data, size_t n)
// {
//     for (size_t i = 0; i < n; i++)
//         free(data[i]);
//     free(data);
// }

int matrix_addition(double **a, size_t a_n, size_t a_m, double **b, size_t b_n, size_t b_m, \
    double ***c, size_t *c_n, size_t *c_m)
{
    if (a_n != a_m || b_n != b_m)
        return NEGATIVE_SIZE_MATRIX;

    *c = allocated_matrix(a_n, a_m);
    if (c == NULL)
        return NEGATIVE_ALLOC;

    *c_n = a_n;
    *c_m = a_m;

    for (size_t i = 0; i < a_n; i++)
    {
        for (size_t j = 0; j < a_m; j++)
            (*c)[i][j] = a[i][j] + b[i][j];
    }

    return OK;
}


int matrix_multiplication(double **a, size_t a_n, size_t a_m, double **b, size_t b_n, size_t b_m, \
    double ***c, size_t *c_n, size_t *c_m)
{
    if (a_n != b_m || a_m != b_n)
        return NEGATIVE_SIZE_MATRIX;
    
    *c = allocated_matrix(a_n, b_m);

    if (c == NULL)
        return NEGATIVE_ALLOC;

    *c_n = a_n;
    *c_m = b_m;

    for (size_t i = 0; i < a_n; i++)
    {
        for (size_t j = 0; j < b_m; j++)
        {
            c[i][j] = 0;
            for (size_t k = 0; k < a_m; k++)
                (*c)[i][j] += a[k][i] * b[j][k];
        }
    }
    return OK;
}
