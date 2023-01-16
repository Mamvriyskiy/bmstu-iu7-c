#include <stdio.h>
#include <check.h>

typedef int (*fn_filter)(const int *array, const size_t lenl, int *tmp, size_t *tmp_lenl);

//длина нового массива не известна(память не выделена)
START_TEST(test_filter_not_len_new_array)
{
    int arr[] = { 3, 9, 16, 7, 8 };
    size_t len = 5;
    size_t result_len = 0;

    size_t absolute_len = 2;
    size_t absolute_rc = 1;

    void *handle = dlopen("lib.so", RTLD_NOW);
    ck_assert_ptr_ne(handle, NULL);
    fn_filter filter = (fn_filter) dlsym(handle, "filter");
    ck_assert_ptr_ne(handle, NULL);

    int rc = filter(arr, len, NULL, &result_len);
    ck_assert_int_eq(rc, absolute_rc);
    ck_assert_int_eq(result_len, absolute_len);

    dlclose(handle);
}
END_TEST



Suite* filter_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("filter");

    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    // tcase_add_test(tc_pos, test_filter_only_sqr);
    // tcase_add_test(tc_pos, test_filter_zero_len);
    // tcase_add_test(tc_pos, test_filter_sqr);
    // tcase_add_test(tc_neg, test_filter_not_enough_len);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}