#include <stdio.h>
#include "../inc/work_file.h"
#include "../inc/error.h"

int count_quantity_number(FILE *file, size_t *count)
{
    int el, error = OK;
    while (error == OK && !feof(file))
    {
        if (fscanf(file, "%d", &el) == OK_SCANF)
            *count += 1;
        else   
            error = NEGATIVE_SCANF;
    }   
    rewind(file);
    return error;
}

int read_number_from_file(FILE *file, int *pb, int *pe)
{
    int rc = OK;
    while (rc == OK && pb < pe)
    {
        if (fscanf(file, "%d", pb++) != OK_SCANF)
            rc = NEGATIVE_SCANF;    
    }
    return rc;
}

void fill_file(FILE *file, int *pb, int *pe)
{
    while (pb < pe)
    {
        fprintf(file, "%d\n", *pb);
        pb++;
    }
}
