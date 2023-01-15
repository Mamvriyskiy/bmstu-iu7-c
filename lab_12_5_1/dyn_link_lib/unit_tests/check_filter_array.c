#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include "key.h"
#include "check_main.h"
#include "ext_error.h"

//Не найдены элементы, удовлетворяющие условие
START_TEST(test_count_correct_element_no_search)
{
    int n = 6;
    long long int suml = 12330;
    int p[] = {1, 2, 3, 4, 5, 12345};
    size_t count = 0, result_count = 0;
    count = count_correct_element(p, p + n, suml);
    ck_assert_uint_eq(count, result_count);
}
END_TEST

//Простой поиск количества элементов
START_TEST(test_count_correct_element_usual_search)
{
    int n = 6;
    long long int suml = -12330;
    int p[] = {1, 2, 3, 4, 5, -12345};
    size_t count = 0, result_count = 5;
    count = count_correct_element(p, p + n, suml);
    ck_assert_uint_eq(count, result_count);
}
END_TEST

//Поиск количества элементов в массиве, содержащем похожие числа
START_TEST(test_count_correct_element_array_with_same_element)
{
    int n = 6;
    long long int suml = -1;
    int p[] = {0, 0, 0, 0, 0, -1};
    size_t count = 0, result_count = 5;
    count = count_correct_element(p, p + n, suml);
    ck_assert_uint_eq(count, result_count);
}
END_TEST

//Значение суммы равно 0
START_TEST(test_create_sum_zero_suml)
{
    int n = 6;
    long long int suml = 0;
    long long int suml_result = 0;
    int p[] = {100, 200, 500, -650, -150, 0};
    suml = create_sum(p, p + n);
    ck_assert_int_eq(suml, suml_result);
}
END_TEST

//Поиск суммы в массиве, состоящем из одинаковых элементов
START_TEST(test_create_sum_array_with_same_element)
{
    int n = 6;
    long long int suml = 0;
    long long int suml_result = 600;
    int p[] = {100, 100, 100, 100, 100, 100};
    suml = create_sum(p, p + n);
    ck_assert_int_eq(suml, suml_result);
}
END_TEST

//Поиск суммы в массиве, длина которого равна 1
START_TEST(test_create_sum_array_len_one)
{
    int n = 1;
    long long int suml = 0;
    long long int suml_result = 55;
    int p[] = {55};
    suml = create_sum(p, p + n);
    ck_assert_int_eq(suml, suml_result);
}
END_TEST

//Простой поиск элементов
START_TEST(test_search_right_element_usual_search)
{
    int n = 5;
    long long int suml = -8;
    int arr_1[] = {55, 34, 2, -45, -54};
    int arr_2[4] = { 0 };
    int result_arr[] = {55, 34, 2, -45};
    search_right_element(arr_1, arr_1 + n, arr_2, suml);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    ck_assert_int_eq(error, OK);
}
END_TEST

//Поиск элементов в массиве, содержащем похожие числа
START_TEST(test_search_right_element_array_with_zero)
{
    int n = 5;
    long long int suml = -8;
    int arr_1[] = {0, 0, 0, 0, -1};
    int arr_2[4] = { 0 };
    int result_arr[] = {0, 0, 0, 0};
    search_right_element(arr_1, arr_1 + n, arr_2, suml);
    int error = cmp_array(arr_2, result_arr, sizeof(result_arr));
    ck_assert_int_eq(error, OK);
}
END_TEST

//Найден только один элемент
START_TEST(test_search_right_element_array_with_one_right_result)
{
    int n = 5;
    long long int suml = 2011;
    int arr_1[] = {1234, 23, 54, 200, 500};
    int arr_2[1] = { 0 };
    int result_arr[] = {1234};
    search_right_element(arr_1, arr_1 + n, arr_2, suml);
    int error = cmp_array(arr_2, result_arr, sizeof(result_arr));
    ck_assert_int_eq(error, OK);
}
END_TEST

//Поиск элементов в массиве, который содержит только положительные числа
START_TEST(test_key_array_with_only_positive_element)
{
    int rc = OK;

    int arr1_b[] = {35, 64, 235, 634, 43, 62, 35, 3124, 324};
    int *arr1_e = arr1_b + 9;
    int suml = 4470;

    int *pb_dst = malloc(sizeof(int));

    int arr2[] = {3124};

    rc = key(arr1_b, arr1_e, pb_dst, suml);

    if (!rc)
        rc = cmp_array(pb_dst, arr2, sizeof(arr2));

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

//Поиск элементов в массиве, который содержит похожие числа
START_TEST(test_key_array_with_zero)
{
    int rc = OK;

    int arr1_b[] = {0, 0, 0, 0, 0, -1};
    int *arr1_e = arr1_b + 6;

    int suml = -1;

    int *pb_dst = malloc(5 * sizeof(int));

    int arr2[] = {0, 0, 0, 0, 0};

    rc = key(arr1_b, arr1_e, pb_dst, suml);

    if (!rc)
        rc = cmp_array(pb_dst, arr2, sizeof(arr2));

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

//Поиск элементов в массиве, который содержит только отрицательные числа
START_TEST(test_key_array_with_only_negative_element)
{
    int rc = OK;

    int arr1_b[] = {-12, -45, -1, -34, -5};
    int *arr1_e = arr1_b + 5;

    int suml = -97;

    int *pb_dst = malloc(2 * sizeof(int));

    int arr2[] = {-12, -1};

    rc = key(arr1_b, arr1_e, pb_dst, suml);

    if (!rc)
        rc = cmp_array(pb_dst, arr2, sizeof(arr2));

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

//Поиск элементов в массиве, который содержит разные числа
START_TEST(test_key_array_with_mixed_element)
{
    int rc = OK;

    int n = 5;
    int arr1_b[] = {-12, 2, -1, 0, -5};
    int *arr1_e = arr1_b + n;

    int suml = -16;

    int *pb_dst = malloc(3 * sizeof(int));

    int arr2[] = {2, -1, 0};

    rc = key(arr1_b, arr1_e, pb_dst, suml);

    if (!rc)
        rc = cmp_array(pb_dst, arr2, sizeof(arr2));

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

//Передача нулевого указателя
START_TEST(test_key_null)
{
    int *arr1_b = NULL;
    int *arr1_e = NULL;

    int *pb_dst = NULL;

    int suml = 10;

    int rc = key(arr1_b, arr1_e, pb_dst, suml);

    ck_assert_int_eq(rc, 6);
}
END_TEST

Suite *filter_suite()
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("count_correct_element");

    tc_neg = tcase_create("negatieves");
    tcase_add_test(tc_neg, test_key_null);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positieves");
    //count_correct_element
    tcase_add_test(tc_pos, test_count_correct_element_no_search);
    tcase_add_test(tc_pos, test_count_correct_element_usual_search);
    tcase_add_test(tc_pos, test_count_correct_element_array_with_same_element);
    //create_sum
    tcase_add_test(tc_pos, test_create_sum_zero_suml);
    tcase_add_test(tc_pos, test_create_sum_array_with_same_element);
    tcase_add_test(tc_pos, test_create_sum_array_len_one);
    //search_right_element
    tcase_add_test(tc_pos, test_search_right_element_usual_search);
    tcase_add_test(tc_pos, test_search_right_element_array_with_zero);
    tcase_add_test(tc_pos, test_search_right_element_array_with_one_right_result);
    //key
    tcase_add_test(tc_pos, test_key_array_with_zero);
    tcase_add_test(tc_pos, test_key_array_with_only_positive_element);
    tcase_add_test(tc_pos, test_key_array_with_only_negative_element);
    tcase_add_test(tc_pos, test_key_array_with_mixed_element);

    suite_add_tcase(s, tc_pos);

    return s;
}

