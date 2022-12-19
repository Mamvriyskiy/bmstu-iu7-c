#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <check.h>
#include "polinom_struct.h"

/**
 * Сравнение двух списков
 * 
 * @param [in] list_1 Указатель на начало списка
 * @param [in] list_2 Указатель на начало списка
 * 
 * Данная функция сравнивает два списка по данным, которые содержат элементы списка
 */
int compare_list(polinom_t *list_1, polinom_t *list_2);

/**
 * Создание списка
 * 
 * @param [out] head Указатель на начало списка
 * @param [in] arr Указатель на массив целых чисел
 * @param [in] n Длина массива целых чисел
 * 
 * Данная функция осуществляет создание списка с помощью массива целых чисел
 */
int make_list(polinom_t **head, int *arr, size_t n);

Suite *math_op_suite();
Suite *work_list_suite();

#endif
