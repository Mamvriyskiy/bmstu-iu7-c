#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/error.h"
#include "../inc/work_file.h"
#include "../inc/sort_array.h"
#include "../inc/filter_array.h"

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
                        {
                            mysort(array, count, sizeof(int), compare);
                            fill_file(output_file, array, array + count);
                            free(array);
                        }
                        else if (!strcmp(argv[3], "f"))
                        {
                            int *pb_key_array = NULL;
                            int *pe_key_array = NULL;
                            error = key(array, array + count, &pb_key_array, &pe_key_array);
                            if (error == OK)
                            {
                                count = pe_key_array - pb_key_array;
                                mysort(pb_key_array, count + 1, sizeof(int), compare);
                                fill_file(output_file, pb_key_array, pe_key_array + 1);
                            }
                            free(pb_key_array);
                        }
                        else
                            error = NEGATIVE_ARGV;
                    }
                }
                else 
                    error = NEGATIVE_MEMORY_ALLOCATION;
            }
            fclose(input_file);
            fclose(output_file);
        }
        else 
            error = NON_OPEN_FILE;
    }
    else 
        error = NEGATIVE_ARGS;
    return error;
}
