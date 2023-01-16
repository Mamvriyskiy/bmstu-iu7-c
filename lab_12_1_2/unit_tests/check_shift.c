#include <stdio.h>
#include <check.h>
#include <dlfcn.h>
#include "check_main.h"

typedef void (*fn_shift)(int *array, const size_t lenl, size_t k);

//сдвиг на ноль элементов
START_TEST(test_create_shift_zero)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t lenl = 8;
    size_t k = 0;

    int result[] = {1, 2, 3, 4, 5, 6, 7, 8};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_shift shift = (fn_shift) dlsym(lib, "shift");
    ck_assert_ptr_ne(lib, NULL);

    shift(array, lenl, k);

    ck_assert_int_eq(memcmp(array, result, lenl * sizeof(int)), 0);

    dlclose(lib);
}
END_TEST

//сдвиг длину массива
START_TEST(test_create_shift_lenl_array)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t lenl = 8;
    size_t k = 8;

    int result[] = {1, 2, 3, 4, 5, 6, 7, 8};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_shift shift = (fn_shift) dlsym(lib, "shift");
    ck_assert_ptr_ne(lib, NULL);

    shift(array, lenl, k);

    ck_assert_int_eq(memcmp(array, result, lenl * sizeof(int)), 0);

    dlclose(lib);
}
END_TEST

//сдвиг на половину длины
START_TEST(test_create_shift_half_lenl)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t lenl = 8;
    size_t k = 4;

    int result[] = {5, 6, 7, 8, 1, 2, 3, 4};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_shift shift = (fn_shift) dlsym(lib, "shift");
    ck_assert_ptr_ne(lib, NULL);

    shift(array, lenl, k);

    ck_assert_int_eq(memcmp(array, result, lenl * sizeof(int)), 0);

    dlclose(lib);
}
END_TEST

//сдвиг на несколько циклов
START_TEST(test_create_shift_some_cycles)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t lenl = 8;
    size_t k = 28;

    int result[] = {5, 6, 7, 8, 1, 2, 3, 4};

    void *lib = dlopen("libarr.so", RTLD_NOW);
    ck_assert_ptr_ne(lib, NULL);

    fn_shift shift = (fn_shift) dlsym(lib, "shift");
    ck_assert_ptr_ne(lib, NULL);

    shift(array, lenl, k);

    ck_assert_int_eq(memcmp(array, result, lenl * sizeof(int)), 0);

    dlclose(lib);
}
END_TEST



Suite* shift_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("filter");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    //sift
    tcase_add_test(tc_pos, test_create_shift_zero);
    tcase_add_test(tc_pos, test_create_shift_lenl_array);
    tcase_add_test(tc_pos, test_create_shift_half_lenl);
    tcase_add_test(tc_pos, test_create_shift_some_cycles);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}
