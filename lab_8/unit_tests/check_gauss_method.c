#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include "gauss_method.h"
#include "check_main.h"

//Не найдены элементы, удовлетворяющие условие
START_TEST(test_count_correct_element_no_search)
{
    int n = 5;
    double p[] = {5, 25, 30, 35, 5};
    double result = {1.0, 5.0, 6.0, 7.0, 1.0};
    division_line(p, 0, n);
    ck_assert_uint_eq(cmp_array(p, result, sizeof(result)), OK);
}
END_TEST

Suite *gauss_suite()
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("count_correct_element");

    tc_neg = tcase_create("negatieves");


    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positieves");
    tcase_add_test(tc_pos, test_count_correct_element_no_search);


    suite_add_tcase(s, tc_pos);

    return s;
}
