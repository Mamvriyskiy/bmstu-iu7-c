#include <stdio.h>
#include <check.h>
#include <string.h>
#include "check_main.h"

int cmp_array(void *arr1, void *arr2, long size)
{
    return memcmp(arr1, arr2, size);
}

int main()
{
    //CHECK_GAUSS_METHOD
    Suite *s = gauss_suite();

    SRunner *runner_s = srunner_create(s);

    srunner_run_all(runner_s, CK_VERBOSE);

    int no_failed = srunner_ntests_failed(runner_s);
    
    srunner_free(runner_s);

    // //CHECK_SORT_ARRAY
    // Suite *p = sort_suite();

    // SRunner *runner_p = srunner_create(p);

    // srunner_run_all(runner_p, CK_VERBOSE);

    // no_failed = srunner_ntests_failed(runner_p);
    
    // srunner_free(runner_p);

    return no_failed;
}