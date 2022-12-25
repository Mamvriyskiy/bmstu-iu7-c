#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ext_error.h"
#include "work_file.h"
#include "sorted.h"
#include "key.h"

int main(int args, char **argv)
{
    int error = OK;
    if (args == 3 || (args == 4 && !strcmp(argv[3], "f")))
    {
        FILE *input_file = fopen(argv[1], "r");
        if (input_file != NULL)
        {
            size_t count;
            error = count_quantity_number(input_file, &count);
            rewind(input_file);
            if (error == OK && count > 0)
            {
                int *array = NULL;
                array = malloc(count * sizeof(int));
                if (array != NULL)
                {
                    error = read_number_from_file(input_file, array, array + count);
                    if (error == OK)
                    {
                        if (args == 3)
                        {
                            mysort(array, count, sizeof(int), compare);
                            error = fill_file(argv[2], array, array + count);
                        }
                        else
                        {
                            int *pb_key_array = NULL;
                            int *pe_key_array = NULL;
                            error = key(array, array + count, &pb_key_array, &pe_key_array);
                            if (error == OK)
                            {
                                count = pe_key_array - pb_key_array;
                                mysort(pb_key_array, count, sizeof(int), compare);
                                error = fill_file(argv[2], pb_key_array, pe_key_array);
                            }
                            free(pb_key_array);
                        }
                    }
                    free(array);
                }
                else 
                    error = NEGATIVE_MEMORY_ALLOCATION;
            }
            fclose(input_file);
        }
        else 
            error = NON_OPEN_FILE;
    }
    else 
        error = NEGATIVE_ARGS;
    return error;
}
