#include <stdio.h>
#include <check.h>
#include "../inc/check_main.h"

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = filter_suite(s);
    s = sort_suite(s);

    return s;
}

int main()
{
    Suite *s = tests_suite();

    SRunner *runner = srunner_create(s);;
    
    srunner_run_all(runner, CK_VERBOSE);

    int no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return no_failed;
}

int cmp_array(int *arr1, int *arr2, long lenl)
{
    for (int i = 0; i < lenl; i++)
    {
        if (arr1[i] != arr2[i])
            return NEGATIVE_CMP;
    }
    return OK;
}
