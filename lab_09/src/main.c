#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "product.h"
#include "product_array.h"

int main(int args, char **argv)
{
    int error = OK;
    if (args != 2 && args != 3)
        return NEGATIVE_ARGS;
    
    size_t len_array = 0;
    product_t *array = NULL;

    error = create_struct_array_ex(argv[1], &len_array, &array);

    if (error == OK)
    {
        if (args == 2) 
        {
            sort_density_array(array, len_array, difference_disteny_product);
            print_all_array(array, len_array);
        } 
        else
        {
            if (!strcmp(argv[2], "ALL"))
                print_all_array(array, len_array);
            else 
                error = print_with_condition(array, len_array, argv[2]);
        }
    }
    
    if (array != NULL)
        free_struct(array, len_array);

    return error;
}

