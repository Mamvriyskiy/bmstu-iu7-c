#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include <math.h>
#include "check_main.h"
#include "product.h"

//Простая смена позициями структур в массиве структур
START_TEST(test_swap_product_first)
{
    product_t a[2] = {{"one", 1, 2}, {"two", 3, 4}};
    product_t b[2] = {{"two", 3, 4}, {"one", 1, 2}};

    swap_product(a, a + 1);

    int error = cmp_array_struct(a, b, 2);
    ck_assert_int_eq(error, OK);
}
END_TEST

//Простая смена позициями структур в массиве структур
START_TEST(test_swap_product_second)
{
    product_t a[2] = {{"a", 1234, 24324}, {"b", 34124, 412}};
    product_t b[2] = {{"b", 34124, 412}, {"a", 1234, 24324}};

    swap_product(a, a + 1);

    int error = cmp_array_struct(a, b, 2);
    ck_assert_int_eq(error, OK);
}
END_TEST


//Простая смена позициями структур в массиве структур
START_TEST(test_swap_product_third)
{
    product_t a[2] = {{"BigSmall", 1, 2}, {"HiHello", 3, 4}};
    product_t b[2] = {{"HiHello", 3, 4}, {"BigSmall", 1, 2}};

    swap_product(a, a + 1);

    int error = cmp_array_struct(a, b, 2);
    ck_assert_int_eq(error, OK);
}
END_TEST

//Сравнение плотностей с отрицательным реузльтатом
START_TEST(test_difference_disteny_product_negative_result)
{
    product_t a[2] = {{"BigSmall", 1, 2}, {"HiHello", 3, 4}};

    int error = difference_disteny_product(a, a + 1);

    ck_assert_int_eq(error, -1);
}
END_TEST

//Сравнение плотностей с положительным реузльтатом
START_TEST(test_difference_disteny_product_positive_result)
{
    product_t a[2] = {{"BigSmall", 3, 4}, {"HiHello", 1, 2}};;

    int error = difference_disteny_product(a, a + 1);

    ck_assert_int_eq(error, 2);
}
END_TEST

//Сравнение плотностей с одинаковыми значениями
START_TEST(test_difference_disteny_product_equal_plt)
{
    product_t a[2] = {{"BigSmall", 1, 2}, {"HiHello", 1, 2}};

    int error = difference_disteny_product(a, a + 1);

    ck_assert_int_eq(error, 3);
}
END_TEST


Suite *product_suite()
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("product");

    tc_neg = tcase_create("negatieves");

    //difference_disteny_product
    tcase_add_test(tc_neg, test_difference_disteny_product_negative_result);
    tcase_add_test(tc_neg, test_difference_disteny_product_equal_plt);


    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positieves");
    //swap_product
    tcase_add_test(tc_pos, test_swap_product_first);
    tcase_add_test(tc_pos, test_swap_product_second);
    tcase_add_test(tc_pos, test_swap_product_third);

    //difference_disteny_product
    tcase_add_test(tc_pos, test_difference_disteny_product_positive_result);

    suite_add_tcase(s, tc_pos);

    return s;
}

