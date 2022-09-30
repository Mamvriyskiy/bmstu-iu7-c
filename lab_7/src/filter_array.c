#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/filter_array.h"
#include "../inc/error.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src)
        return UNRIGHNT_INPUT;
    
    long long int suml = 0;
    suml = create_sum(pb_src, pe_src);

    printf("%lld\n", suml);
    size_t n = 0;
    n = count_correct_element(pb_src, pe_src, suml);
    
    if (n == 0)
        return EL_NOT_FOUND;
    
    int *p = malloc(n * sizeof(int));

    if (!p)
        return NEGATIVE_MEMORY_ALLOCATION;

    *pb_dst = p;
    *pe_dst = *pb_dst + n - 1;
    search_right_element(pb_src, pe_src, *pb_dst, suml);

    return OK;
}

void search_right_element(const int *pb_src, const int *pe_src, int *pb_tmp, long long int suml)
{
    while (pb_src < pe_src - 1)
    {
        suml -= *pb_src;
        if (*pb_src > suml)
        {
            *pb_tmp = *pb_src;
            pb_tmp++;
        }
        pb_src++;
    }
}

long long int create_sum(const int *pb_src, const int *pe_src)
{
    long long int suml = 0;
    while (pb_src < pe_src)
    {
        suml += *pb_src;
        pb_src++;
    }
    return suml;
}

size_t count_correct_element(const int *pb_src, const int *pe_src, long long int suml)
{
    size_t k = 0;
    while (pb_src < pe_src - 1)
    {
        suml -= *pb_src;
        if (*pb_src > suml)
            k++;
        pb_src++;
    }
    return k;
}

