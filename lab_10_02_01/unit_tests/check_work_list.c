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
#include "work_list.h"

//новый элемент не создан
START_TEST(test_push_list_back_negative_tmp)
{
    int error = OK;
    polinom_t *head = NULL;
    
    polinom_t *tmp = NULL;

    head = push_list_back(head, tmp);

    if (head != NULL)
        error = NEGATIVE_TEST;

    ck_assert_int_eq(error, OK);
}
END_TEST

//закидывание элемента в конец несозданного полинома
START_TEST(test_push_list_back_head_null)
{
    int error = OK;
    
    polinom_t *head = NULL;


    polinom_t *tmp = polinom_create(2, 2);

    if (!tmp)
        error = NEGATIVE_ALLOC;

    if (!error)
    {
        head = push_list_back(head, tmp);
        if (head->next != NULL || head->mult != 2 || head->degree != 2)
            error = NEGATIVE_TEST;
    }

    if (head)
        polinom_free(head);

    ck_assert_int_eq(error, OK);
}
END_TEST

//закидывание элемента в конец уже сущетсвующего полинома
START_TEST(test_push_list_back_posive_test)
{
    int error = OK;

    int arr_head[] = {1, 6, 24, 2, 3};

    polinom_t *head = NULL;

    error = make_list(&head, arr_head, 6); 

    if (!error)
    {
        if (!error)
        {

            polinom_t *tmp = polinom_create(10, 2);

            if (!error)
            {
                head = push_list_back(head, tmp);
                polinom_t *cur = head;
                for (; cur->next; cur = cur->next);

                if (cur->next != NULL || cur->mult != 10 || cur->degree != 2)
                    error = NEGATIVE_TEST;
            }
        }
    }

    if (head)
        polinom_free(head);

    ck_assert_int_eq(error, OK);
}
END_TEST

//простой случай создания элемента полинома
START_TEST(test_polinom_create_first_positive)
{
    int error = OK;
    polinom_t *head = NULL;

    head = polinom_create(2, 2);

    if (head->next != NULL || head->mult != 2 || head->degree != 2)
        error = NEGATIVE_TEST;

    if (head)
        free(head);

    ck_assert_int_eq(error, OK);
}
END_TEST

//простой случай создания элемента полинома
START_TEST(test_polinom_create_second_positive)
{
    int error = OK;
    polinom_t *head = NULL;

    head = polinom_create(5, -3);

    if (head->next != NULL || head->mult != 5 || head->degree != -3)
        error = NEGATIVE_TEST;

    if (head)
        free(head);
        
    ck_assert_int_eq(error, OK);
}
END_TEST

//простой случай создания элемента полинома
START_TEST(test_polinom_create_third_positive)
{
    int error = OK;
    polinom_t *head = NULL;

    head = polinom_create(-3, 1);

    if (head->next != NULL || head->mult != -3 || head->degree != 1)
        error = NEGATIVE_TEST;

    if (head)
        free(head);
        
    ck_assert_int_eq(error, OK);
}
END_TEST

START_TEST(test_copy_list)
{
    int error = OK;

    int arr[] = {8, 3, 2, 2};

    polinom_t *head = NULL;
    polinom_t *result = NULL;

    error = make_list(&head, arr, 4);  
         
    if (!error)
    {
        result = copy_list(head);
        error = compare_list(head, result);
    }

    if (head)
        polinom_free(head);

    if (result)
        polinom_free(result);

    ck_assert_int_eq(error, OK);
}
END_TEST

Suite *work_list_suite()
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("count_correct_element");

    tc_neg = tcase_create("negatieves");
    tcase_add_test(tc_neg, test_push_list_back_head_null);


    suite_add_tcase(s, tc_neg);
    

    tc_pos = tcase_create("positieves");

    //push_list_back
    tcase_add_test(tc_pos, test_push_list_back_negative_tmp);
    tcase_add_test(tc_pos, test_push_list_back_posive_test);

    //polinom_create
    tcase_add_test(tc_pos, test_polinom_create_first_positive);
    tcase_add_test(tc_pos, test_polinom_create_second_positive);
    tcase_add_test(tc_pos, test_polinom_create_third_positive);

    tcase_add_test(tc_pos, test_copy_list);

    suite_add_tcase(s, tc_pos);

    return s;
}
