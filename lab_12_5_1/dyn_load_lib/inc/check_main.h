#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <stdlib.h>

#define EPS 0.00000001

/**
 * Сравнение двух массивов
 * 
 * @param [in] arr1 Указатель на начало массива
 * @param [in] arr2 Указатель на начало массива
 * @param [in] size Размер массивов
 * 
 * Данная функция осуществляет сравнение двух массивов
*/
int cmp_array(void *arr1, void *arr2, long size);

/**
 * Создание двух элементов
 * 
 * @param [in] first_el Указатель на первый элемент
 * @param [in] second_el Указатель на второй элемент
 * 
 * Данная функция осуществляет сравнение двух элементов типа double
*/
int compare_double(const void *first_el, const void *second_el);

/**
 * Создание двух элементов
 * 
 * @param [in] first_el Указатель на первый элемент
 * @param [in] second_el Указатель на второй элемент
 * 
 * Данная функция осуществляет сравнение двух элементов типа char
*/
int compare_char(const void *first_el, const void *second_el);

Suite *filter_suite();
Suite *sort_suite();

#endif