#include <stdio.h>
#include <string.h>
#include "shift.h"

void shift(int *arr, size_t len, size_t k)
{
    k = k % len;
    if (!k || !arr)
        return;

    for (size_t i = 0; i < k; i++)
    {
        int el = arr[0];

        for (size_t j = 0; j < len - 1; j++)
            arr[j] = arr[j + 1];

        arr[len - 1] = el;
    }
}
