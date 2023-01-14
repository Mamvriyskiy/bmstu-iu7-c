#include <stdio.h>
#include <check.h>
#include <dlfcn.h>
#include "check_main.h"
#include "ext_error.h"

typedef void (*fn_mysort)(void *pb, size_t n, size_t size, int (*cmp)(const void *, const void *));
typedef int (*fn_compare)(const void *first_el, const void *second_el);
typedef void (*fn_swap_el)(void *first_el, void *second_el, size_t lenl);

//Меняет местами элементы типа int
START_TEST(test_swap_el_normal_swap_one)
{
    int first_el = 34;
    int second_el = 1234;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_swap_el swap_el = (fn_swap_el) dlsym(lib, "swap_el");
    ck_assert_ptr_ne(swap_el, NULL);
    
    swap_el(&first_el, &second_el, sizeof(first_el));

    dlclose(lib);

    ck_assert_int_eq(first_el, 1234);
    ck_assert_int_eq(second_el, 34);
}
END_TEST

//Меняет местами элементы типа int
START_TEST(test_swap_el_normal_swap_second)
{
    int first_el = -1;
    int second_el = 34;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_swap_el swap_el = (fn_swap_el) dlsym(lib, "swap_el");
    ck_assert_ptr_ne(swap_el, NULL);
    
    swap_el(&first_el, &second_el, sizeof(first_el));

    dlclose(lib);

    ck_assert_int_eq(first_el, 34);
    ck_assert_int_eq(second_el, -1);
}
END_TEST

//Меняет местами элементы типа double
// START_TEST(test_swap_el_double_swap)
// {
//     double first_el = -0.1;
//     double second_el = 34.65;

//     void *lib = dlopen("libarr.so", RTLD_NOW);
//     ck_assert_ptr_ne(lib, NULL);

//     fn_swap_el swap_el = (fn_swap_el) dlsym(lib, "swap_el");
//     ck_assert_ptr_ne(swap_el, NULL);

//     swap_el(&first_el, &second_el, sizeof(first_el));

//     dlclose(lib);

//     ck_assert_double_eq_tol(first_el, 34.65, EPS);
//     ck_assert_double_eq_tol(second_el, -0.1, EPS);
// }
// END_TEST

//Меняет местами элементы типа char
START_TEST(test_swap_el_char_swap)
{
    char first_el[] = "34";
    char second_el[] = "24";

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_swap_el swap_el = (fn_swap_el) dlsym(lib, "swap_el");
    ck_assert_ptr_ne(swap_el, NULL);
    
    swap_el(&first_el, &second_el, sizeof(first_el));

    dlclose(lib);

    ck_assert_str_eq(first_el, "24");
    ck_assert_str_eq(second_el, "34");
}
END_TEST

//Обыкновенное сравнение элементов
START_TEST(test_compare_normal_one)
{
    int first_el = 12;
    int second_el = -1;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    int a = compare(&first_el, &second_el);

    dlclose(lib);

    ck_assert_int_eq(a, 1);
}   
END_TEST

//Обыкновенное сравнение элементов
START_TEST(test_compare_normal_second)
{
    int first_el = 34;
    int second_el = 1234;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    int a = compare(&first_el, &second_el);

    dlclose(lib);

    ck_assert_int_eq(a, -1);
}
END_TEST

//Обыкновенное сравнение элементов
START_TEST(test_compare_normal_third)
{
    int first_el = 34;
    int second_el = 34;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    int a = compare(&first_el, &second_el);

    dlclose(lib);

    ck_assert_int_eq(a, 0);
}
END_TEST

//Сортировка одного элемента
START_TEST(test_mysort_one_element)
{
    int n = 1;
    int arr_1[] = {55};
    int result_arr[] = {55};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка упорядоченного по возрастанию массива
START_TEST(test_mysort_array_ascending_order)
{
    int n = 6;
    int arr_1[] = {1, 2, 3, 4, 5, 6};
    int result_arr[] = {1, 2, 3, 4, 5, 6};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка упорядоченного по убыванию массива
START_TEST(test_mysort_array_descending_order)
{
    int n = 6;
    int arr_1[] = {6, 5, 4, 3, 2, 1};
    int result_arr[] = {1, 2, 3, 4, 5, 6};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка массива, содержащего повторяющиеся элементы
START_TEST(test_mysort_array_with_identical_elements)
{
    int n = 6;
    int arr_1[] = {1, 2, 3, 3, 2, 1};
    int result_arr[] = {1, 1, 2, 2, 3, 3};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка упорядоченного по возрастанию массива типа double
START_TEST(test_mysort_array_ascending_order_double)
{
    int n = 6;
    double arr_1[] = {1.0, 2.5, 3.1, 4.9, 5.0, 6.1};
    double result_arr[] = {1.0, 2.5, 3.1, 4.9, 5.0, 6.1};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare_double);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка упорядоченного по убыванию массива типа double
START_TEST(test_mysort_array_descending_order_double)
{
    int n = 6;
    double arr_1[] = {6.1, 5, 4.9, 3.1, 2.5, 1.0};
    double result_arr[] = {1.0, 2.5, 3.1, 4.9, 5, 6.1};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare_double);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);   

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка массива типа double
START_TEST(test_mysort_array_double)
{
    int n = 6;
    double arr_1[] = {6.0, 5.6, 3.1, 3.0, 14.5, 1.0};
    double result_arr[] = {1.0, 3.0, 3.1, 5.6, 6.0, 14.5};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare_double);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка упорядоченного по возрастанию массива типа char
START_TEST(test_mysort_array_ascending_order_char)
{
    int n = 6;
    char arr_1[] = {'1', '2', '3', '4', '5', '6'};
    char result_arr[] = {'1', '2', '3', '4', '5', '6'};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare_char);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка упорядоченного по убыванию массива типа char
START_TEST(test_mysort_array_descending_order_char)
{
    int n = 6;
    char arr_1[] = {'6', '5', '4', '3', '2', '1'};
    char result_arr[] = {'1', '2', '3', '4', '5', '6'};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare_char);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

//Сортировка массива типа char
START_TEST(test_mysort_array_char)
{
    int n = 6;
    char arr_1[] = {'5', '2', '4', '3', '6', '1'};
    char result_arr[] = {'1', '2', '3', '4', '5', '6'};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_compare compare = (fn_compare) dlsym(lib, "compare");
    ck_assert_ptr_ne(compare, NULL);

    fn_mysort mysort = (fn_mysort) dlsym(lib, "mysort");
    ck_assert_ptr_ne(mysort, NULL);

    mysort(arr_1, n, sizeof(arr_1[0]), compare_char);
    int error = cmp_array(arr_1, result_arr, sizeof(result_arr));
    
    dlclose(lib);

    ck_assert_int_eq(error, OK);
}
END_TEST

Suite *sort_suite()
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("count_correct_element");

    tc_neg = tcase_create("negatieves");
    
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positieves");

    //swap_el
    tcase_add_test(tc_pos, test_swap_el_normal_swap_one);
    tcase_add_test(tc_pos, test_swap_el_normal_swap_second);
    // tcase_add_test(tc_pos, test_swap_el_double_swap);
    tcase_add_test(tc_pos, test_swap_el_char_swap);

    //compare
    tcase_add_test(tc_pos, test_compare_normal_one);
    tcase_add_test(tc_pos, test_compare_normal_second);
    tcase_add_test(tc_pos, test_compare_normal_third);

    //mysort
    tcase_add_test(tc_pos, test_mysort_one_element);
    tcase_add_test(tc_pos, test_mysort_array_ascending_order);
    tcase_add_test(tc_pos, test_mysort_array_descending_order);
    tcase_add_test(tc_pos, test_mysort_array_with_identical_elements);
    tcase_add_test(tc_pos, test_mysort_array_ascending_order_double);
    tcase_add_test(tc_pos, test_mysort_array_descending_order_double);
    tcase_add_test(tc_pos, test_mysort_array_double);
    tcase_add_test(tc_pos, test_mysort_array_ascending_order_char);
    tcase_add_test(tc_pos, test_mysort_array_descending_order_char);
    tcase_add_test(tc_pos, test_mysort_array_char);

    suite_add_tcase(s, tc_pos);

    return s;
}
