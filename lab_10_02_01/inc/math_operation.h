#ifndef _MATH_OPERATION_
#define _MATH_OPERATION_

#include "polinom_struct.h"

/**
 * Подсчет полинома
 * 
 * @param [in] head Указатель на начало списка
 * @param [in] el Значение x полинома
 * @param [out] suml Результат вычисление полинома
 * 
 * Данная функция осуществляет подсчет занечние полинома со значением x
 */
int calculation_polinom(polinom_t *head, int el, int *suml);

/**
 * Получение производной
 * 
 * @param [in] head Указатель на начало списка
 * 
 * Данная функция осуществляет получение производной полинома
 */
polinom_t *derivative_math(polinom_t *head);

/**
 * Сложение двух списков
 * 
 * @param [in] head Указатель на начало списка
 * @param [in] second_head Указатель на начало списка
 * @param [out] result Указатель на указатель на начало списка
 * 
 * Данная функция осуществляет сложение двух списков по степеням
 */
int sum_two_polinom(polinom_t *head, polinom_t *second_head, polinom_t **result);



/**
 * Разбиение списка
 * 
 * @param [in] head Указатель на начало списка
 * @param [inout] even_list Указатель на указатель на начало списка
 * @param [inout] odd_list Указатель на указатель на начало списка
 * 
 * Данная функция осуществляет разбиение полинома на четные и нечетные степени
 */
int split_list(polinom_t *head, polinom_t **even_list, polinom_t **odd_list);


#endif
