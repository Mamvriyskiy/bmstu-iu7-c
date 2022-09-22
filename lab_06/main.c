#include <stdio.h>
#include <string.h>
#include "error.h"
#include "product.h"
#include "product_array.h"

int main(int args, char **argv)
{
    int error = OK;
    if (args == 2 || args == 3)
    {
        FILE *file = fopen(argv[1], "r");
        if (file != NULL)
        {
            product_t product_information[MAX_LEN];
            size_t len_array = 0;
            error = read_subject_array(file, product_information, &len_array);
            if (error == OK)
            {
                if (args == 2) 
                {
                    sort_density_array(product_information, len_array, difference_disteny_product);
                    print_all_array(product_information, len_array);
                } 
                else
                {
                    if (!strcmp(argv[2], "ALL"))
                        print_all_array(product_information, len_array);
                    else 
                        error = print_with_condition(product_information, len_array, argv[2]);
                }
            }
            fclose(file);
        }
        else 
            error = NEGATIVE_OPEN_FILE;
    }
    else
        error = NEGATIVE_ARGS;
    return error;
}
