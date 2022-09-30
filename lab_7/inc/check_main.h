#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include "stdlib.h"

#define NEGATIVE_CMP -1
#define OK 0
#define NEGATIVE_SIZE_ARRAY -2

int cmp_array(int *arr1, int *arr2, long lenl);

Suite *filter_suite(Suite *s);
Suite *sort_suite(Suite *s);

#endif
