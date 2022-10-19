#include <stdio.h>
#include "read_print_matrix.h"
#include "errors.h"

int read_matrix(FILE *f, double **data, size_t n, size_t m, size_t k)
{
    int j, v;
    double z;
    for (size_t i = 0; i < k; i++)
    {
        if (fscanf(f, "%d %d %lf", &j, &v, &z) != SCANF_OK)
            return NEGATIVE_SCANF;
        
        if (j < 1 || j > n || v < 1 || v > m)
            return NEGATIVE_COORD;
            
        data[j - 1][v - 1] = z;
    }
    return OK;
}

int fprint_matrix(char *name_file, double **data, size_t n, size_t m)
{
    FILE *file = fopen(name_file, "w");

    if (file == NULL)
        return NO_OPEN_FILE;

    fprintf(file, "%zu %zu", n, m);
    fprintf(file, "\n");

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            fprintf(file, "%f ", data[i][j]);
        fprintf(file, "\n");
    }

    return OK;
}


