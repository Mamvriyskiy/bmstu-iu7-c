#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "ext_error.h"
#include "work_file.h"
#include "sorted.h"
#include "key.h"

typedef int (*fn_key)(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

typedef void (*fn_mysort)(void *pb, size_t n, size_t size, int (*cmp)(const void *, const void *));

typedef int (*fn_count_quantity_number)(FILE *file, size_t *count);
typedef int (*fn_read_number_from_file)(FILE *file, int *pb, int *pe);
typedef int (*fn_fill_file)(char *name_file, const int *pb, const int *pe);

int main(int args, char **argv)
{
    int error = OK;
    if (args == 3 || (args == 4 && !strcmp(argv[3], "f")))
        return NEGATIVE_ARGS;

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file)
        return NON_OPEN_FILE;

    void *lib = dlopen("libarr.so", RTLD_NOW);

    if (!lib)
    {
        error = NO_OPEN_LIB;
        fclose(input_file);
    }
    else
    {
        fn_count_quantity_number count_number = (fn_count_quantity_number) dlsym(lib, "count_quantity_number");  
        if (!count_number)
        {
            error = NO_SEARCH_FUNC;
            goto out;
        }
        size_t count;
        error = count_number(input_file, &count);
        rewind(input_file);

        if (error == OK && count > 0)
        {
            fn_read_number_from_file read_number = (fn_read_number_from_file) dlsym(lib, "read_number_from_file");  
            if (!read_number)
            {
                error = NO_SEARCH_FUNC;
                goto out;
            }

            int *array = NULL;
            array = malloc(count * sizeof(int));
            if (array)
            {
                error = read_number(input_file, array, array + count);
                if (error != OK)
                    free(array);
            }

            fclose(input_file);

            int *pb_key_array = NULL;
            int *pe_key_array = NULL;
            if (args == 4 && error == OK)
            {
 
                fn_key key = (fn_key) dlsym(lib, "key");
                if (key)
                    error = key(array, array + count, &pb_key_array, &pe_key_array);

                free(array);
            }

            if (error == OK)
            {
                fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
                count = pe_key_array - pb_key_array;
                mysort(pb_key_array, count, sizeof(int), compare);

                if (error == OK)
                {
                    fn_fill_file fill_file = (fn_fill_file) dlsym(lib, "fill_file");
                    if (!fill_file)
                        error = NO_SEARCH_FUNC;
                    else
                    error = fill_file(argv[2], pb_key_array, pe_key_array);
                }
                dlclose(lib);
                free(pb_key_array);
            }
        }
    }

    out:
        fclose(input_file);
        dlclose(lib);
            

    return error;
}

