#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "work_matrix.h"
#include "read_print_matrix.h"

int main(int args, char **argv)
{
    if (args != 4 && args != 5)
        return NEGATIVE_ARGS;
    
    if (strcmp(argv[1], "o") && strcmp(argv[1], "a") && strcmp(argv[1], "m"))
        return NEGATIVE_ARGV;
    
    FILE *mtr_1 = fopen(argv[2], "r");
    if (mtr_1 == NULL)
        return NO_OPEN_FILE;
    
    FILE *mtr_2 = fopen(argv[3], "r");
    if (mtr_2 == NULL)
        return NO_OPEN_FILE;

    int error = OK;

    size_t a_n, a_m, a_k, b_n, b_m, b_k, res_n, res_m, res_k;
    double **a, **b, **res;
    error = create_matrix(mtr_1, &a, &a_n, &a_m, &a_k);
    if (error == OK)
    {
        if (args == 5)
        {
            error = create_matrix(mtr_2, &b, &b_n, &b_m, &b_k);
            if (error == OK)
            {
                if (!strcmp(argv[1], "a"))
                {
                    error = matrix_addition(a, a_n, a_m, b, b_n, b_m, &res, &res_n, &res_m);
                    if (error == OK)
                    {
                        error = fprint_matrix(argv[4], res, res_n, res_m);
                        free(res);
                    }
                }
                else
                {
                    error = matrix_multiplication(a, a_n, a_m, b, b_n, b_m, &res, &res_n, &res_m);
                    if (error == OK)
                    {
                        error = fprint_matrix(argv[4], res, res_n, res_m);
                        free(res);
                    }
                }
                free(b);
            }
        }
        else
        {
            printf("+");
        }      
        free(a);
    }
    return error;
}
