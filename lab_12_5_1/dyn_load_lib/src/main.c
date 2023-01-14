#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "ext_error.h"

typedef int (*fn_key)(const int *pb_src, const int *pe_src, int *pb_dst, long long int suml);
typedef size_t (*fn_count_correct_element)(const int *pb_src, const int *pe_src, long long int suml);
typedef long long int (*fn_create_sum)(const int *pb_src, const int *pe_src);

typedef void (*fn_mysort)(void *pb, size_t n, size_t size, int (*cmp)(const void *, const void *));
typedef int (*fn_compare)(const void *first_el, const void *second_el);

typedef int (*fn_count_quantity_number)(FILE *file, size_t *count);
typedef int (*fn_read_number_from_file)(FILE *file, int *pb, int *pe);
typedef int (*fn_fill_file)(char *name_file, const int *pb, const int *pe);

int main(int args, char **argv)
{
    int error = OK;
    if (args == 3 || (args == 4 && !strcmp(argv[3], "f")))
    {
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
                    {
                        free(array);
                        goto out;
                    }
                }

                fclose(input_file);

                int *pb_key_array = array;
                int *pe_key_array = array + count;
                int *p = NULL;

                if (args == 4 && error == OK)
                {
                    long long int suml = 0;

                    fn_create_sum create_sum = (fn_create_sum) dlsym(lib, "count_quantity_number");  
                    if (!create_sum)
                    {
                        error = NO_SEARCH_FUNC;
                        goto out_free_array;
                    }

                    suml = create_sum(array, array + count);

                    fn_count_correct_element count_element = (fn_count_correct_element) dlsym(lib, "count_quantity_number");  
                    if (!create_sum)
                    {
                        error = NO_SEARCH_FUNC;
                        goto out_free_array;
                    }

                    size_t n = 0;
                    n = count_element(array, array + count, suml);
                    
                    if (n == 0)
                    {
                        error = EL_NOT_FOUND;
                        goto out_free_array;
                    }
                    
                    p = malloc(n * sizeof(int));

                    if (!p)
                    {
                        error = NEGATIVE_MEMORY_ALLOCATION;
                        goto out_free;
                    }

                    pb_key_array = p;
                    pe_key_array = p + n;

                    fn_key key = (fn_key) dlsym(lib, "key");
                    if (key)
                        error = key(array, array + count, pb_key_array, suml);
                    else 
                        error = NO_SEARCH_FUNC;
                }

                if (error == OK)
                {
                    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
                    fn_compare compare = (fn_compare) dlsym(lib, "compare");
                    if (!mysort || !compare)
                        error = NO_SEARCH_FUNC;

                    if (error == OK)
                    {
                        count = pe_key_array - pb_key_array;
                        mysort(pb_key_array, count, sizeof(int), compare);

                        fn_fill_file fill_file = (fn_fill_file) dlsym(lib, "fill_file");
                        if (!fill_file)
                            error = NO_SEARCH_FUNC;
                        else
                            error = fill_file(argv[2], pb_key_array, pe_key_array);
                    }

                    out:
                        fclose(input_file);
                }
                out_free:
                    dlclose(lib);
                    free(p);
                
                out_free_array:
                    free(array);
            }
        }
    }
    else
        error = NEGATIVE_ARGS;
            

    return error;
}

