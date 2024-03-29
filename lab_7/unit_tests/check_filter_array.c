#include <stdio.h>
#include <check.h>
#include "../inc/filter_array.h"
#include "../inc/check_main.h"

//count_correct_element
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

//create_sum
START_TEST(test_create_sum_zero_suml)
{
    int n = 6;
    long long int suml = 0;
    long long int suml_result = 0;
    int p[] = {100, 200, 500, -550, -150, 0};
    suml = create_sum(p, p + n);
    ck_assert_int_eq(suml, suml_result);
}
END_TEST

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

//search_right_element
START_TEST(test_search_right_element_usual_search)
{
    int n = 5;
    long long int suml = -8;
    int arr_1[] = {55, 34, 2, -45, -54};
    int arr_2[4] = { 0 };
    int result_arr[] = {55, 34, 2, -45};
    search_right_element(arr_1, arr_1 + n, arr_2, suml);
    int error = cmp_array(arr_2, result_arr, 4);
    ck_assert_int_eq(error, OK);

}
END_TEST

START_TEST(test_search_right_element_array_with_zero)
{
    int n = 5;
    long long int suml = -8;
    int arr_1[] = {0, 0, 0, 0, -1};
    int arr_2[4] = { 0 };
    int result_arr[] = {0, 0, 0, 0};
    search_right_element(arr_1, arr_1 + n, arr_2, suml);
    int error = cmp_array(arr_2, result_arr, 4);
    ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_search_right_element_array_with_one_right_result)
{
    int n = 5;
    long long int suml = -8;
    int arr_1[] = {1234, 23, 54, 200, 500};
    int arr_2[1] = { 0 };
    int result_arr[] = {1234};
    search_right_element(arr_1, arr_1 + n, arr_2, suml);
    int error = cmp_array(arr_2, result_arr, 1);
    ck_assert_int_eq(error, OK);
}
END_TEST

//key
START_TEST(test_key_array_with_only_positive_element)
{
    int arr1_b[] = {35, 64, 235, 634, 43, 62, 35, -3124, 324};
    int *arr1_e = arr1_b + 9;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {35, 35, 43, 62, 64, 235, 634};
    int len2 = 7;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    long len1 = pe_dst - pb_dst;
    int rc = OK;

    if (len1 != len2)
        rc = NEGATIVE_SIZE_ARRAY;
    else
        rc = cmp_array(pb_dst, arr2, len1);

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_key_array_with_zero)
{
    int arr1_b[] = {0, 0, 0, 0, 0, -1};
    int *arr1_e = arr1_b + 5;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {0, 0, 0, 0, 0};
    int len2 = 5;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    long len1 = pe_dst - pb_dst;
    int rc = OK;

    if (len1 != len2)
        rc = NEGATIVE_SIZE_ARRAY;
    else
        rc = cmp_array(pb_dst, arr2, len1);

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_key_array_with_only_negative_element)
{
    int arr1_b[] = {-12, -45, -1, -34, -5};
    int *arr1_e = arr1_b + 5;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {-12, -1};
    int len2 = 2;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    long len1 = pe_dst - pb_dst;
    int rc = OK;

    if (len1 != len2)
        rc = NEGATIVE_SIZE_ARRAY;
    else
        rc = cmp_array(pb_dst, arr2, len1);

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_key_array_with_mixed_element)
{
    int arr1_b[] = {-12, 2, -1, 0, -5};
    int *arr1_e = arr1_b + 5;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int arr2[] = {2, -1, 0};
    int len2 = 3;

    key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    long len1 = pe_dst - pb_dst;
    int rc = OK;

    if (len1 != len2)
        rc = NEGATIVE_SIZE_ARRAY;
    else
        rc = cmp_array(pb_dst, arr2, len1);

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_key_array_with_one_element)
{
    int arr1_b[] = {1};
    int *arr1_e = arr1_b + 1;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST


START_TEST(test_key_no_search_element)
{
    int arr1_b[] = {34, 12, -1, 34, 1234};
    int *arr1_e = arr1_b + 5;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_key_null)
{
    int *arr1_b = NULL;
    int *arr1_e = NULL;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr1_b, arr1_e, &pb_dst, &pe_dst);

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite *filter_suite(Suite *s)
{
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("count_correct_element");

    tc_neg = tcase_create("negatieves");
    tcase_add_test(tc_neg, test_key_array_with_one_element);
    tcase_add_test(tc_neg, test_key_no_search_element);
    tcase_add_test(tc_neg, test_key_null);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positieves");
    //count_correct_element
    tcase_add_test(tc_neg, test_count_correct_element_no_search);
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

