#include <stdio.h>
#include <string.h>
#include "work_array.h"

void mysort(void *pb, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
    char *p_start = pb;
    char *p_end = p_start + (n - 1) * size;
    while (p_start < p_end)
    {
        for (char *i = p_end; i > p_start; i -= size)
        {
            if (cmp(i - size, i) > 0)
                swap_el(i - size, i, size);
                
        }
        p_start += size; 

        for (char *j = p_start; j < p_end; j += size)
        {
            if (cmp(j, j + size) > 0)
                swap_el(j, j + size, size);
        }
        p_end -= size;
    }
}

int compare(const void *first_el, const void *second_el)
{
    return *((int *) first_el) - *((int *) second_el);
}

void swap_el(void *first_el, void *second_el, size_t lenl)
{
    char tmp[lenl];
    memcpy(tmp, first_el, lenl);
    memcpy(first_el, second_el, lenl);
    memcpy(second_el, tmp, lenl);
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    
}