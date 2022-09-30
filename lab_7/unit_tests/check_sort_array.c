#include <stdio.h>
#include <check.h>
#include "../inc/sort_array.h"
#include "../inc/check_main.h"

//swap_el
START_TEST(test_swap_el_normal_swap_one)
{
    int arr[] = {34, 12, -1, 34, 1234};
    int *first_el = arr;
    int *second_el = arr + 5;

    int arr_result[] = {1234, 12, -1, 34, 34};

    swap_el(first_el, second_el, sizeof(int));

    int rc = cmp_array(arr, arr_result, 5);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_swap_el_normal_swap_second)
{
    int arr[] = {34, 12, -1, 34, 1234};
    int *first_el = arr + 3;
    int *second_el = arr + 4;

    int arr_result[] = {1234, 12, 34, -1, 34};

    swap_el(first_el, second_el, sizeof(int));

    int rc = cmp_array(arr, arr_result, 5);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_swap_el_normal_swap_third)
{
    int arr[] = {34, 12, -1, 34, 1234};
    int *first_el = arr + 2;
    int *second_el = arr + 3;

    int arr_result[] = {1234, -1, 12, 34, 34};

    swap_el(first_el, second_el, sizeof(int));

    int rc = cmp_array(arr, arr_result, 5);

    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite *sort_suite(Suite *s)
{
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("count_correct_element");

    tc_neg = tcase_create("negatieves");
    
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positieves");

    tcase_add_test(tc_pos, test_swap_el_normal_swap_one);
    tcase_add_test(tc_pos, test_swap_el_normal_swap_second);
    tcase_add_test(tc_pos, test_swap_el_normal_swap_third);

    suite_add_tcase(s, tc_pos);

    return s;
}

