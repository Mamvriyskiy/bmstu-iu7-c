#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ext_error.h"
#include "key.h"

int key(const int *pb_src, const int *pe_src, int *pb_dst, long long int suml)
{
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src)
        return UNRIGHNT_INPUT;

    search_right_element(pb_src, pe_src, pb_dst, suml);

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

