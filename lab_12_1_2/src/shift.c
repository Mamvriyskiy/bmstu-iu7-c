#include <stdio.h>
#include <string.h>
#include "shift.h"

void shift(int *array, const size_t lenl, size_t k)
{
    k = k % lenl;
    if (!k || !array)
        return;

    for (size_t i = 0; i < k; i++)
    {
        int el = array[0];

        for (size_t j = 0; j < lenl - 1; j++)
            array[j] = array[j + 1];

        array[lenl - 1] = el;
    }
}
