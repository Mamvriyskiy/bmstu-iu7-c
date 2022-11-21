#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "errors.h"

int read_subject(FILE *file, double *weight, double *volume, char *buf)
{
    ssize_t lenl_char;
    size_t len = 0;

    lenl_char = getline(&buf, &len, file);

    if (lenl_char == -1)
        return NEGATIVE_SCANF;

    if (lenl_char && buf[lenl_char - 1] == '\n')
    {
        buf[lenl_char - 1] = '\0';
        lenl_char--;
    }
    
    if (fscanf(file, "%lf\n", weight) != SCANF_OK)
        return NEGATIVE_SCANF;

    if ((*weight) <= 0)
        return UNRIGHT_WEIGHT;
 
    if (fscanf(file, "%lf\n", volume) != SCANF_OK)
        return NEGATIVE_SCANF;

    if ((*volume) <= 0)
        return UNRIGHT_VOLUME;

    return OK;
}

void swap_product(product_t *first_product, product_t *second_product)
{
    product_t buffer = *first_product;
    *first_product = *second_product;
    *second_product = buffer;
}

int difference_disteny_product(const product_t *first_product, const product_t *second_product)
{
    double plt = first_product->weight / first_product->volume - second_product->weight / second_product->volume;
    if (plt > 0)
        return POSITIVE_CMP;
    else if (fabs(plt) < EPS)
        return EQUAL_CMP;
    return NEGATIVE_CMP;
}

void print_inpformation(product_t *product)
{
    printf("%s\n", product->name_product);
    printf("%f\n", product->weight);
    printf("%f\n", product->volume);
}


