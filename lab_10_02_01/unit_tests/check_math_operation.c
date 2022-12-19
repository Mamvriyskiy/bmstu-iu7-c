#include <stdio.h>
#include <check.h>
#include <string.h>
#include <stdlib.h>
#include "polinom_struct.h"
#include "io.h"
#include "math_operation.h"
#include "check_main.h"
#include "allocated.h"
#include "errors.h"

//Простой тест подсчтета полинома
START_TEST(test_calculation_polinom_first_positive)
{
    int error = OK;

    int arr[] = {8, 2, 12, 1, 1, 0};
    polinom_t *head = NULL;

    error = make_list(&head, arr, 6);   

    if (head && !error)
    {
        int suml = 0, el = 7, result_suml = 477;

        calculation_polinom(head, el, &suml);

        if (suml != result_suml)
            error = NEGATIVE_TEST;
    }

    if (head)
        polinom_free(head);


    ck_assert_int_eq(error, OK);
}
END_TEST

//Подсчет полинома, состоящего из одного элемента
START_TEST(test_calculation_polinom_one_el)
{
    int error = OK;

    int arr[] = {8, 2};
    polinom_t *head = NULL;

    error = make_list(&head, arr, 2);   

    if (head && !error)
    {
        int suml = 0, el = 2, result_suml = 32;

        calculation_polinom(head, el, &suml);

        if (suml != result_suml)
            error = NEGATIVE_TEST;
    }

    if (head)
        polinom_free(head);


    ck_assert_int_eq(error, OK);
}
END_TEST

//Подсчет полинома при отрицательном значении x
START_TEST(test_calculation_polinom_negative_el)
{
    int error = OK;

    int arr[] = {8, 2};
    polinom_t *head = NULL;

    error = make_list(&head, arr, 2);   

    if (head && !error)
    {
        int suml = 0, el = -2, result_suml = 32;

        calculation_polinom(head, el, &suml);

        if (suml != result_suml)
            error = NEGATIVE_TEST;
    }

    if (head)
        polinom_free(head);


    ck_assert_int_eq(error, OK);
}
END_TEST

//Получение отрицательного значения полинома
START_TEST(test_calculation_polinom_negative_result)
{
    int error = OK;

    int arr[] = {8, 3, 2, 2};
    polinom_t *head = NULL;

    error = make_list(&head, arr, 4);   

    if (head && !error)
    {
        int suml = 0, el = -2, result_suml = -56;

        calculation_polinom(head, el, &suml);

        if (suml != result_suml)
            error = NEGATIVE_TEST;
    }

    if (head)
        polinom_free(head);


    ck_assert_int_eq(error, OK);
}
END_TEST

//простой случай получения производной
START_TEST(test_derivative_math_first_positive)
{
    int error = OK;

    int arr[] = {8, 3, 2, 2};
    int res_arr[] = {24, 2, 4, 1};

    polinom_t *head = NULL;
    polinom_t *result = NULL;

    error = make_list(&head, arr, 4);  
    if (!error)
        error = make_list(&result, res_arr, 4); 
         
    if (!error)
    {
        error = derivative_math(head);
        if (!error)
            error = compare_list(head, result);
    }

    if (head)
        polinom_free(head);

    if (result)
        polinom_free(result);

    ck_assert_int_eq(error, OK);
}
END_TEST

//простой случай получения производной
START_TEST(test_derivative_math_second_positive)
{
    int error = OK;

    int arr[] = {1, 5, 8, 3, 2, 2, 1, 1};
    int res_arr[] = {5, 4, 24, 2, 4, 1, 1, 0};

    polinom_t *head = NULL;
    polinom_t *result = NULL;

    error = make_list(&head, arr, 8);  
    if (!error)
        error = make_list(&result, res_arr, 8);

    if (!error)
    {
        error = derivative_math(head);
        if (!error)
            error = compare_list(head, result);
    }

    if (head)
        polinom_free(head);

    if (result)
        polinom_free(result);

    ck_assert_int_eq(error, OK);
}
END_TEST

//полином содержит отрицательные коэффиценты
START_TEST(test_derivative_math_third_neagtive_el)
{
    int error = OK;

    int arr[] = {-1, 5, -8, 3, 2, 2, 1, 1};
    int res_arr[] = {-5, 4, -24, 2, 4, 1, 1, 0};

    polinom_t *head = NULL;
    polinom_t *result = NULL;

    error = make_list(&head, arr, 8);  
    if (!error)
        error = make_list(&result, res_arr, 8); 
         
    if (!error)
    {
        error = derivative_math(head);
        if (!error)
            error = compare_list(head, result);
    }

    if (head)
        polinom_free(head);
    
    if (result)
        polinom_free(result);


    ck_assert_int_eq(error, OK);
}
END_TEST

//один полином больше другого
START_TEST(test_sum_two_polinom_one_bigger_other)
{
    int error = OK;

    int arr_a[] = {4, 2, 12, 1, 1, 0};
    int arr_b[] = {8, 1, 12, 0};
    int res_arr[] = {4, 2, 20, 1, 13, 0};

    polinom_t *head_a = NULL;
    polinom_t *head_b = NULL;
    polinom_t *result = NULL;

    error = make_list(&head_a, arr_a, 6);  
    if (!error)
        error = make_list(&head_b, arr_b, 4); 

    if (!error)
        error = make_list(&result, res_arr, 6); 
         
    if (!error)
    {
        polinom_t *c = NULL;
        error = sum_two_polinom(head_a, head_b, &c);
        if (!error)
            error = compare_list(result, c);

        if (c)
            polinom_free(c);
    }

    if (head_a)
        polinom_free(head_a);

    if (head_b)
        polinom_free(head_b);
    
    if (result)
        polinom_free(result);

    ck_assert_int_eq(error, OK);
}
END_TEST

//полиномы равны
START_TEST(test_sum_two_polinom_same_polinom)
{
    int error = OK;

    int arr_a[] = {4, 2, 12, 1, 1, 0};
    int arr_b[] = {4, 2, 12, 1, 1, 0};
    int res_arr[] = {8, 2, 24, 1, 2, 0};

    polinom_t *head_a = NULL;
    polinom_t *head_b = NULL;
    polinom_t *result = NULL;

    error = make_list(&head_a, arr_a, 6);  
    if (!error)
        error = make_list(&head_b, arr_b, 6); 

    if (!error)
        error = make_list(&result, res_arr, 6); 
         
    if (!error)
    {
        polinom_t *c = NULL;
        error = sum_two_polinom(head_a, head_b, &c);
        if (!error)
            error = compare_list(result, c);

        if (c)
            polinom_free(c);
    }

    if (head_a)
        polinom_free(head_a);

    if (head_b)
        polinom_free(head_b);
    
    if (result)
        polinom_free(result);

    ck_assert_int_eq(error, OK);
}
END_TEST

//полиномы содержат отрицательные коэффиценты
START_TEST(test_sum_two_negative_el)
{
    int error = OK;

    int arr_a[] = {-4, 2, 12, 1, -1, 0};
    int arr_b[] = {5, 2, 12, 1, -1, 0};
    int res_arr[] = {1, 2, 24, 1, -2, 0};

    polinom_t *head_a = NULL;
    polinom_t *head_b = NULL;
    polinom_t *result = NULL;

    error = make_list(&head_a, arr_a, 6);  
    if (!error)
        error = make_list(&head_b, arr_b, 6); 

    if (!error)
        error = make_list(&result, res_arr, 6); 
         
    if (!error)
    {
        polinom_t *c = NULL;
        error = sum_two_polinom(head_a, head_b, &c);
        if (!error)
            error = compare_list(result, c);
        
        if (c)
            polinom_free(c);
    }

    if (head_a)
        polinom_free(head_a);

    if (head_b)
        polinom_free(head_b);
    
    if (result)
        polinom_free(result);

    ck_assert_int_eq(error, OK);
}
END_TEST

//простое разбиение полинома
START_TEST(test_split_list_postive)
{
    int error = OK;

    int arr_res_even[] = {1, 4, 2, 2};
    int arr_res_odd[] = {24, 3, 3, 1};
    int arr_head[] = {1, 4, 24, 3, 2, 2, 3, 1};

    polinom_t *head = NULL;
    polinom_t *even_head_res = NULL;
    polinom_t *odd_head_res = NULL;

    error = make_list(&head, arr_head, 6);  
    if (!error)
        error = make_list(&even_head_res, arr_res_even, 4); 

    if (!error)
        error = make_list(&odd_head_res, arr_res_odd, 4); 
         
    if (!error)
    {
        polinom_t *even_head = NULL;
        polinom_t *odd_head = NULL;
        error = split_list(head, &even_head, &odd_head);

        if (!error)
            error = compare_list(even_head_res, even_head);

        if (!error)
            error = compare_list(odd_head, odd_head_res);

        if (odd_head)
            polinom_free(odd_head);

        if (even_head)
            polinom_free(even_head);
    }

    if (head)
        polinom_free(head);

    if (even_head_res)
        polinom_free(even_head_res);
    
    if (odd_head_res)
        polinom_free(odd_head_res);

    ck_assert_int_eq(error, OK);
}
END_TEST

//полином с четными степенями пустой
START_TEST(test_split_list_even_empty)
{
    int error = OK;

    int arr_res_odd[] = {1, 5, 24, 3, 3, 1};
    int arr_head[] = {1, 5, 24, 3, 3, 1};

    polinom_t *head = NULL;
    polinom_t *odd_head_res = NULL;

    error = make_list(&head, arr_head, 6);  

    if (!error)
        error = make_list(&odd_head_res, arr_res_odd, 6); 
         
    if (!error)
    {
        polinom_t *even_head = NULL;
        polinom_t *odd_head = NULL;
        error = split_list(head, &even_head, &odd_head);

        if (even_head != NULL)
            error = NEGATIVE_TEST;

        if (!error)
            error = compare_list(odd_head, odd_head_res);

        if (odd_head)
            polinom_free(odd_head);
    }

    if (head)
        polinom_free(head);

    if (odd_head_res)
        polinom_free(odd_head_res);

    ck_assert_int_eq(error, OK);
}
END_TEST

//полином с нечетными степенями пустой
START_TEST(test_split_list_odd_empty)
{
    int error = OK;

    int arr_res_even[] = {1, 6, 24, 2, 3, 0};
    int arr_head[] = {1, 6, 24, 2, 3, 0};

    polinom_t *head = NULL;
    polinom_t *even_head_res = NULL;

    error = make_list(&head, arr_head, 6);  

    if (!error)
        error = make_list(&even_head_res, arr_res_even, 6); 
         
    if (!error)
    {
        polinom_t *even_head = NULL;
        polinom_t *odd_head = NULL;
        error = split_list(head, &even_head, &odd_head);

        if (odd_head != NULL)
            error = NEGATIVE_TEST;

        if (!error)
            error = compare_list(odd_head, even_head_res);

        if (even_head)
            polinom_free(even_head);
    }

    if (head)
        polinom_free(head);

    if (even_head_res)
        polinom_free(even_head_res);

    ck_assert_int_eq(error, OK);
}
END_TEST

Suite *math_op_suite()
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("count_correct_element");

    tc_neg = tcase_create("negatieves");


    suite_add_tcase(s, tc_neg);
    

    tc_pos = tcase_create("positieves");

    // calculation_polinom
    tcase_add_test(tc_pos, test_calculation_polinom_first_positive);
    tcase_add_test(tc_pos, test_calculation_polinom_one_el);
    tcase_add_test(tc_pos, test_calculation_polinom_negative_el);
    tcase_add_test(tc_pos, test_calculation_polinom_negative_result);

    // derivative_math
    tcase_add_test(tc_pos, test_derivative_math_first_positive);
    tcase_add_test(tc_pos, test_derivative_math_second_positive);
    tcase_add_test(tc_pos, test_derivative_math_third_neagtive_el);


    // sum_two_polinom
    tcase_add_test(tc_pos, test_sum_two_polinom_one_bigger_other);
    tcase_add_test(tc_pos, test_sum_two_polinom_same_polinom);
    tcase_add_test(tc_pos, test_sum_two_negative_el);


    // split_list
    tcase_add_test(tc_pos, test_split_list_postive);
    tcase_add_test(tc_pos, test_split_list_even_empty);
    tcase_add_test(tc_pos, test_split_list_odd_empty);

    suite_add_tcase(s, tc_pos);

    return s;
}
