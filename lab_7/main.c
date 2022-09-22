#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "work_file.h"
#include "work_array.h"

int main(int args, char **argv)
{
    int error = OK;
    if (args == 3 || args == 4)
    {
        FILE *input_file = fopen(argv[1], "r");
        FILE *output_file = fopen(argv[2], "w");
        if (input_file != NULL)
        {
            size_t count = 0;
            error = count_quantity_number(input_file, &count);
            if (error == OK)
            {
                int *array = NULL;
                array = malloc(count * sizeof(int));
                if (array != NULL)
                {
                    error = read_number_from_file(input_file, array, array + count);
                    if (error == OK)
                    {
                        if (args == 3)
                            mysort(array, count, sizeof(int), compare);
                        else 
                        {
                            // key;
                            // new_array;
                            // sort;
                            printf("hi");
                        }
                        fill_file(output_file, array, array + count);
                    }
                }
                else 
                    error = NEGATIVE_MEMORY_ALLOCATION;
                free(array);
            }
        }
        else 
            error = NON_OPEN_FILE;
    }
    else 
        error = NEGATIVE_ARGS;
    return error;
}