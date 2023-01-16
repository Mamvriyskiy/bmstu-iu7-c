#include <stdio.h>
#include <check.h>
#include <dlfcn.h>
#include "check_main.h"

typedef int (*fn_filter)(const int *array, const size_t lenl, int *tmp, size_t *tmp_lenl);
typedef size_t (*fn_create_len)(const int *array, const size_t lenl);
typedef int (*fn_check_square)(int num);

//длина нового массива не известна(память не выделена)
START_TEST(test_filter_not_len_new_array)
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t lenl = 5;

    size_t res_lenl = 0;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_filter filter = (fn_filter) dlsym(lib, "filter");
    ck_assert_ptr_ne(lib, NULL);

    int rc = filter(arr, lenl, NULL, &res_lenl);

    ck_assert_int_eq(rc, 1);
    ck_assert_int_eq(res_lenl, 2);

    dlclose(lib);
}
END_TEST

//полные квадраты не найдены
START_TEST(test_filter_no_square)
{
    int arr[] = {3, 2, 3, 8, 5};
    int arr_res[2];

    size_t lenl = 5;

    size_t res_lenl = 2;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_filter filter = (fn_filter) dlsym(lib, "filter");
    ck_assert_ptr_ne(lib, NULL);

    int rc = filter(arr, lenl, arr_res, &res_lenl);

    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(res_lenl, 0);

    dlclose(lib);
}
END_TEST

//полные квадраты найдены
START_TEST(test_filter_search_square)
{
    int arr[] = {1, 2, 3, 4, 5};
    int tmp[2];
    int result[2] = {1, 4};

    size_t lenl = 5;

    size_t tmp_lenl = 2;
    size_t res_lenl = 2;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_filter filter = (fn_filter) dlsym(lib, "filter");
    ck_assert_ptr_ne(lib, NULL);

    int rc = filter(arr, lenl, tmp, &tmp_lenl);

    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(res_lenl, 2);
    ck_assert_int_eq(memcmp(tmp, result, res_lenl * sizeof(int)), 0);

    dlclose(lib);
}
END_TEST

//отрицательныйе числа
START_TEST(test_filter_negative_num)
{
    int arr[] = {1, 2, 3, -4, 5, -9, 16};
    int tmp[2];
    int result[2] = {1, 16};

    size_t lenl = 7;

    size_t tmp_lenl = 7;
    size_t res_lenl = 2;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_filter filter = (fn_filter) dlsym(lib, "filter");
    ck_assert_ptr_ne(lib, NULL);

    int rc = filter(arr, lenl, tmp, &tmp_lenl);

    ck_assert_int_eq(rc, 0);
    ck_assert_int_eq(res_lenl, 2);
    ck_assert_int_eq(memcmp(tmp, result, res_lenl * sizeof(int)), 0);

    dlclose(lib);
}
END_TEST

//полные квадраты не найдены
START_TEST(test_create_len_no_search)
{
    int arr[] = {7, 2, 3, 3, 5};

    size_t lenl = 5;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_create_len create_len = (fn_create_len) dlsym(lib, "create_len");
    ck_assert_ptr_ne(lib, NULL);

    size_t result = create_len(arr, lenl);

    ck_assert_int_eq(result, 0);

    dlclose(lib);
}
END_TEST

//полные квадраты найдены
START_TEST(test_create_len_search_square)
{
    int arr[] = {1, 2, 3, 4, 5};

    size_t lenl = 5;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_create_len create_len = (fn_create_len) dlsym(lib, "create_len");
    ck_assert_ptr_ne(lib, NULL);

    size_t result = create_len(arr, lenl);

    ck_assert_int_eq(result, 2);

    dlclose(lib);
}
END_TEST

//массив состоит полностью из полных квадратов
START_TEST(test_create_len_all_square)
{
    int arr[] = {1, 2, 9, 4, 225};

    size_t lenl = 5;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_create_len create_len = (fn_create_len) dlsym(lib, "create_len");
    ck_assert_ptr_ne(lib, NULL);

    size_t result = create_len(arr, lenl);

    ck_assert_int_eq(result, 4);

    dlclose(lib);
}
END_TEST

//число не является полным квадратом
START_TEST(test_create_square_false)
{
    int num = 3;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_check_square check_square = (fn_check_square) dlsym(lib, "check_square");
    ck_assert_ptr_ne(lib, NULL);

    int error = check_square(num);

    ck_assert_int_eq(error, 0);

    dlclose(lib);
}
END_TEST

//число является полным квадратом
START_TEST(test_create_square_true)
{
    int num = 4;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_check_square check_square = (fn_check_square) dlsym(lib, "check_square");
    ck_assert_ptr_ne(lib, NULL);

    int error = check_square(num);

    ck_assert_int_eq(error, 1);

    dlclose(lib);
}
END_TEST

//отрицательное число
START_TEST(test_create_negative_num)
{
    int num = 3;

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_check_square check_square = (fn_check_square) dlsym(lib, "check_square");
    ck_assert_ptr_ne(lib, NULL);

    int error = check_square(num);

    ck_assert_int_eq(error, 0);

    dlclose(lib);
}
END_TEST


Suite* filter_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("filter");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    //filter
    tcase_add_test(tc_pos, test_filter_not_len_new_array);
    tcase_add_test(tc_pos, test_filter_no_square);
    tcase_add_test(tc_pos, test_filter_search_square);
    tcase_add_test(tc_neg, test_filter_negative_num);

    //create_len
    tcase_add_test(tc_neg, test_create_len_no_search);
    tcase_add_test(tc_neg, test_create_len_search_square);
    tcase_add_test(tc_neg, test_create_len_all_square);

    //check_square 
    tcase_add_test(tc_neg, test_create_square_true);
    tcase_add_test(tc_neg, test_create_square_false);
    tcase_add_test(tc_neg, test_create_negative_num);



    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
