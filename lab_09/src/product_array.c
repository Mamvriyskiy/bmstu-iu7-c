#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "product.h"
#include "product_array.h"

int create_struct_array_ex(char *name_file, size_t *len_array, product_t **array)
{
    int error = OK;
    FILE *file = fopen(name_file, "r");
    if (!file)
        return NO_OPEN_FILE;

    error = count_lenl_array(file, len_array);

    if (error == OK)
    {
        rewind(file);

        *array = malloc(*len_array * sizeof(product_t));
        if (array == NULL)
            return NEGATIVE_ALLOC;

        // error = create_array(file, *array, *len_array);
    }

    fclose(file);

    return error;
}

int count_lenl_array(FILE *file, size_t *len_array)
{
    size_t i = 0;
    int rc = OK;
    while (rc == OK && !feof(file))
    {
        double weight, volume;
        char *buf = NULL;
        rc = read_subject(file, &weight, &volume, buf);
        free(buf);
        if (rc == OK)
            i++;
    }
    *len_array = i;

    return rc;
}

int create_array(FILE *file, product_t *array, size_t lenl)
{
    int error = OK;
    for (size_t i = 0; i < lenl && error == OK; i++)
    {
        double weight, volume;
        char *buf = NULL;
        error = read_subject(file, &weight, &volume, buf);
        if (error == OK)
        {
            array->weight = weight;
            array->volume = volume;

            array->name_product = strdup(buf);

            if (array->name_product == NULL)
                error = NEGATIVE_ALLOC;   
        }
        
        free(buf);
    }

    return error;
}

void print_all_array(product_t *product_information, size_t len_array)
{
    for (size_t i = 0; i < len_array; i++)
        print_inpformation(product_information + i);
}

void free_struct(product_t *array, size_t lenl)
{
    for (size_t i = 0; i < lenl; i++)
        free(array[i].name_product);

    free(array);
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
            if (cmp(product_information + j, product_information + j + 1) == 2)
                swap_product(product_information + j, product_information + j + 1);
        } 
    }
}
