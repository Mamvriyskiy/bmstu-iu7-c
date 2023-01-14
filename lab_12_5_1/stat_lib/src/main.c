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
                
                if (array)
                {
                    error = read_number_from_file(input_file, array, array + count);
                    
                    fclose(input_file);

                    if (error == OK)
                    {
                        int *pb_key_array = array;
                        int *pe_key_array = array + count;
                        int *p = NULL;

                        if (args == 4)
                        {
                            long long int suml = 0;
                            suml = create_sum(array, array + count);

                            size_t n = 0;
                            n = count_correct_element(array, array + count, suml);
                            
                            if (n == 0)
                            {
                                error = EL_NOT_FOUND;
                                goto out_free_array;
                            }
                            
                            p = malloc(n * sizeof(int));

                            if (!p)
                            {
                                error = NEGATIVE_MEMORY_ALLOCATION;
                                goto out_free_array;
                            }

                            pb_key_array = p;
                            pe_key_array = p + n;

                            error = key(array, array + count, pb_key_array, suml);
                        }

                        if (error == OK)
                        {
                            count = pe_key_array - pb_key_array;
                            mysort(pb_key_array, count, sizeof(int), compare);
                            error = fill_file(argv[2], pb_key_array, pe_key_array);
                        }

                        if (p)
                            free(p);
                    }

                    out_free_array:
                        free(array);
                }
                else 
                    error = NEGATIVE_MEMORY_ALLOCATION;
            }
        }
        else 
            error = NON_OPEN_FILE;
    }
    else 
        error = NEGATIVE_ARGS;
    
    return error;
}
