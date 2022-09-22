#include <stdio.h>
#include <string.h>
#include "product.h"
#include "error.h"

int read_subject(FILE *file, product_t *current_struct)
{
    char buf[TITLE_LEN + 2];

    if (!fgets(buf, sizeof(buf), file))
        return NEGATIVE_SCANF;

    size_t len = strlen(buf);

    if (len && buf[len - 1] == '\n')
    {
        buf[len - 1] = '\0';
        len--;
    }
    
    if (!len || len > TITLE_LEN)
        return NEGATIVE_STRUCT;

    float weight_product;
    if (fscanf(file, "%f\n", &weight_product) != SCANF_OK)
        return NEGATIVE_SCANF;

    if (weight_product <= 0)
        return UNRIGHT_WEIGHT;
 
    float volume_product;
    if (fscanf(file, "%f\n", &volume_product) != SCANF_OK)
        return NEGATIVE_SCANF;

    if (volume_product <= 0)
        return UNRIGHT_VOLUME;

    strcpy(current_struct->name_product, buf);

    current_struct->weight = weight_product;
    current_struct->volume = volume_product;
    
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
    if (first_product->weight / first_product->volume - second_product->weight / second_product->volume > 0)
        return POSITIVE_CMP;
    return NEGATIVE_CMP;
}

void print_inpformation(product_t *product)
{
    printf("%s\n", product->name_product);
    printf("%f\n", product->weight);
    printf("%f\n", product->volume);
}