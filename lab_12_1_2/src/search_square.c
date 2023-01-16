#include <stdio.h>
#include <math.h>
#include "search_square.h"

int check_square(int num)
{
    if (num < 0)
        return 0;
    return sqrt(num) - (int) sqrt(num) <= EPS;
}

size_t create_len(const int *array, const size_t lenl)
{
    size_t count = 0;
    for (size_t i = 0; i < lenl; i++)
        if (check_square(array[i]))
            count++;
    return count;
}

int filter(const int *array, const size_t lenl, int *tmp, size_t *tmp_lenl)
{
    size_t len = create_len(array, lenl);
    if (len > *tmp_lenl)
    {
        *tmp_lenl = len;
        return NEW_LEN;
    }

    size_t count = 0;
    for (size_t i = 0; i < lenl; i++)
    {
        if (check_square(array[i]))
        {
            if (count < *tmp_lenl)
                tmp[count++] = array[i];
        }
    }
    *tmp_lenl = count;
    
    return OK;
}
