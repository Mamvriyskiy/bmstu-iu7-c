#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include <math.h>
#include "check_main.h"
#include "product.h"
#include "product_array.h"

//Сортировка массива структур, состоящего из двух элементов
START_TEST(test_sort_density_array_no_sort)
{
    product_t a[2] = {{"one", 1, 2}, {"two", 3, 4}};
    product_t b[2] = {{"one", 1, 2}, {"two", 3, 4}};

    sort_density_array(a, 2, difference_disteny_product);

    int error = cmp_array_struct(a, b, 2);
    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка плотнойстей с разными значениями
START_TEST(test_sort_density_array_true_sort)
{
    product_t a[5] = {{"jksjdf", 423, 56}, {"fkajf", 4235, 524}, \
    {"dgdsjg", 4235, 5235}, {"dsfdsg", 48923, 8943}, {"fkaoskf", 414, 4324}};
    product_t b[5] = {{"fkaoskf", 414, 4324}, {"dgdsjg", 4235, 5235}, \
    {"dsfdsg", 48923, 8943}, {"jksjdf", 423, 56}, {"fkajf", 4235, 524}};

    sort_density_array(a, 5, difference_disteny_product);

    int error = cmp_array_struct(a, b, 5);
    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка массива структур, состоящего из одного элемента
START_TEST(test_sort_density_array_one_element)
{
    product_t a[1] = {{"abcd", 3, 2}};
    product_t b[1] = {{"abcd", 3, 2}};

    sort_density_array(a, 1, difference_disteny_product);

    int error = cmp_array_struct(a, b, 1);
    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка массива структур, где плотности расположены по возрастанию
START_TEST(test_sort_density_array_acording_plt)
{
    product_t a[6] = {{"one", 1, 6}, {"two", 1, 5}, {"three", 1, 4}, {"four", 1, 3}, \
    {"five", 1, 2}, {"six", 1, 1}};
    product_t b[6] = {{"one", 1, 6}, {"two", 1, 5}, {"three", 1, 4}, {"four", 1, 3}, \
    {"five", 1, 2}, {"six", 1, 1}};

    sort_density_array(a, 6, difference_disteny_product);

    int error = cmp_array_struct(a, b, 6);
    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка массива структур, где плотности расположены по убыванию
START_TEST(test_sort_density_array_descending_plt)
{
    product_t a[6] = {{"six", 1, 1}, {"five", 1, 2}, {"four", 1, 3}, {"three", 1, 4}, \
    {"two", 1, 5}, {"one", 1, 6}};
    product_t b[6] = {{"one", 1, 6}, {"two", 1, 5}, {"three", 1, 4}, {"four", 1, 3}, \
    {"five", 1, 2}, {"six", 1, 1}};

    sort_density_array(a, 6, difference_disteny_product);

    int error = cmp_array_struct(a, b, 6);
    ck_assert_int_eq(error, OK);
}
END_TEST

Suite *product_array_suite()
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("product_array");

    tc_pos = tcase_create("positieves");

    //sort_density_array
    tcase_add_test(tc_pos, test_sort_density_array_no_sort);
    tcase_add_test(tc_pos, test_sort_density_array_true_sort);
    tcase_add_test(tc_pos, test_sort_density_array_one_element);
    tcase_add_test(tc_pos, test_sort_density_array_acording_plt);
    tcase_add_test(tc_pos, test_sort_density_array_descending_plt);

    suite_add_tcase(s, tc_pos);

    return s;
}
