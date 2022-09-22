#include <stdio.h>
#include <string.h>
#include "product_array.h"
#include "error.h"

int read_subject_array(FILE *file, product_t *product_information, size_t *len_array)
{
    int rc = OK;
    size_t i = 0;
    product_t current_struct = { 0 };
    while (rc == OK && !feof(file))
    {
        rc = read_subject(file, &current_struct);
        if (rc == OK)
        {
            if (i < MAX_LEN)
            {
                product_information[i] = current_struct;
                i++;
            }
            else 
                rc = ERROR_OVERFLOW;
        }
    }
    *len_array = i;
    return rc;
}

void print_all_array(product_t *product_information, size_t len_array)
{
    for (size_t i = 0; i < len_array; i++)
    {
        print_inpformation(product_information + i);
    }
}

int print_with_condition(product_t *product_information, size_t len_array, char *condition)
{ 
    int rc = NO_FOUND_STRUCT, k = 0;
    for (size_t i = 0; i < len_array; i++)
    {
        if (strncmp(condition, product_information[i].name_product, strlen(condition)) == OK)
        {
            print_inpformation(product_information + i);
            k += 1;
        }
    }
    if (k != 0)
        rc = OK;
    return rc;
}

void sort_density_array(product_t *product_information, size_t len_array, int (*cmp)(const product_t *, const product_t *)) 
{
    for (size_t i = 0; i < len_array; i++)
    {
        for (size_t j = 0; j < len_array - 1; j++)
        {
            if (cmp(product_information + j, product_information + j + 1) > 0)
                swap_product(product_information + j, product_information + j + 1);
        } 
    }
}

