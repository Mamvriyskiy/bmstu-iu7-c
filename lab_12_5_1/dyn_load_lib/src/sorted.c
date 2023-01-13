#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorted.h"
#include "ext_error.h"

int compare(const void *first_el, const void *second_el)
{
    int cmp = *((int *) first_el) - *((int *) second_el);
    int res_cmp;
    if (cmp > 0)
        res_cmp = 1;
    else if (cmp == 0)
        res_cmp = 0;
    else 
        res_cmp = -1;

    return res_cmp;
}

void swap_el(void *first_el, void *second_el, size_t lenl)
{
    char tmp[lenl];
    memcpy(tmp, first_el, lenl);
    memcpy(first_el, second_el, lenl);
    memcpy(second_el, tmp, lenl);
}

void mysort(void *pb, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
    char *p_start = pb;
    char *p_end = p_start + n * size;
    char *maxl;

    for (; p_start < p_end; p_end -= size)
    {
        maxl = pb;
        for (char *i = p_start + size; i < p_end; i += size)
        {
            if (cmp(i, maxl) > 0)
                maxl = i;
        }
        swap_el(maxl, p_end - size, size);
    }
}
