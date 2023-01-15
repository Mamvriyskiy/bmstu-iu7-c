#include <stdio.h>
#include <math.h>
#include "search_square.h"

size_t get_len(const int *arr, size_t len)
{
    size_t counter = 0;
    for (size_t i = 0; i < len; i++)
        if (is_square(arr[i]))
            counter++;
    return counter;
}

int is_square(int number)
{
    if (number < 0)
        return 0;
    return sqrt(number) - (int) sqrt(number) <= EPS ? 1 : 0;
}

int filter(const int *src, size_t src_len, int *dst, size_t *dst_len)
{
    size_t len = get_len(src, src_len);
    if (len > *dst_len)
    {
        *dst_len = len;
        return ERR_LEN;
    }

    size_t counter = 0;
    for (size_t i = 0; i < src_len; i++)
    {
        if (is_square(src[i]))
        {
            if (counter < *dst_len)
                dst[counter++] = src[i];
        }
    }
    *dst_len = counter;
    
    return OK;
}
