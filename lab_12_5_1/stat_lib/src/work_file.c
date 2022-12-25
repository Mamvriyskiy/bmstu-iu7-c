#include <stdio.h>
#include "ext_error.h"
#include "work_file.h"

int count_quantity_number(FILE *file, size_t *count)
{
    int el, error = OK;
    *count = 0;
    while (error == OK && !feof(file))
    {
        if (fscanf(file, "%d\n", &el) == OK_SCANF)
            *count += 1;
        else   
            error = NEGATIVE_SCANF;
    }   
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

int fill_file(char *name_file, const int *pb, const int *pe)
{
    FILE *file = fopen(name_file, "w");
    if (file == NULL)
        return NON_OPEN_FILE;
    while (pb < pe)
    {
        fprintf(file, "%d ", *pb);
        pb++;
    }
    fclose(file);
    return OK;
}
