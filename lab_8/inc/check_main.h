#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include "stdlib.h"

#define NEGATIVE_CMP -1
#define OK 0
#define NEGATIVE_SIZE_ARRAY -2
#define EPS 1.0e-7

int cmp_array(void *arr1, void *arr2, long size);

Suite *gauss_suite();
// Suite *sort_suite();

#endif
