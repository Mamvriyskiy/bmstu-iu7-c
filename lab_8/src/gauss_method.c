#include <stdio.h>
#include "work_matrix.h"
#include "gauss_method.h"
#include "errors.h"

int gauss_method(double **a, size_t a_n, size_t a_m, double ***c, size_t *c_n, size_t *c_m)
{
    if (a[0][0] <= 0.000001 && a[0][0] >= -0.0000001)
        return -1;

    *c = allocated_matrix(a_m, 1);

    if (c == NULL)
        return NEGATIVE_ALLOC;

    *c_n = a_n;
    *c_m = 1;

    for (size_t i = 0; i < a_n - 1; i++)
    {
        division_line(a[i], i, a_m);
        sub_line(a, i, a_n, a_m);
    }

    create_result_matrix(a, a_n, a_m, *c, *c_n);

    return OK;
}

void division_line(double *a, size_t k, size_t m)
{
    double div = a[k];
    for (size_t j = k; j < m; j++)
    {
        if (a[j] >= 0.00000001 || a[j] <= -0.00000001)
            a[j] /= div;
    }
}

void sub_line(double **data, size_t k, size_t n, size_t m)
{   
    for (size_t i = k + 1; i < n; i++)
    {
        double a = data[i][k];
        for (size_t j = k; j < m; j++) 
            data[i][j] -= a * data[k][j];
    }
}

void create_result_matrix(double **a, size_t a_n, size_t a_m, double **c, size_t c_n)
{
    for (size_t h = 0; h < c_n; h++)
        c[h][0] = 1;

    for (int k = a_n - 1; k >= 0; k--)
    {
        double result = a[k][a_m - 1];
        size_t l = c_n - 1;
        int j = a_m - 2;
        double suml = 0;
        while (j > k)
        {
            suml += a[k][j] * c[j][0];
            l--;
            j--;
        }
        if (suml <= 0.000001 && suml >= -0.000001)
            c[k][0] = result / a[k][a_m - 2];
        else 
        {
            result -= suml;
            if (a[k][j] < 0)
                c[k][0] = result * -1;
            else 
                c[k][0] = result;
        }
    }
}
