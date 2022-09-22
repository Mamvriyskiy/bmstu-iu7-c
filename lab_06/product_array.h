#ifndef SUBJECT_ARRAY_H
#define SUBJECT_ARRAY_H

#include <stdio.h>
#include "product.h"

#define MAX_LEN 15

/**
 * \fn int read_subject_array(FILE *file, product_t *product_information, size_t *len_array)
 * \breif Заполнение массива структур
 * 
 * @param file Поток ввода
 * @param producr_information Указатель на массив структур
 * @param len_array Указатель на размер массива структур
 * 
 * Данная функция осуществляет заполнение массива структур
*/
int read_subject_array(FILE *file, product_t *product_information, size_t *len_array);

/**
 * \fn void print_all_array(product_t *product_information, size_t len_array)
 * \breif Вывод массива структур
 * 
 * @param producr_information Указатель на массив структур
 * @param len_array Размер массива структур
 * 
 * Данная функция осуществляет вывод массива структур в стандартный поток вывода
*/
void print_all_array(product_t *product_information, size_t len_array);

/**
 * \fn int print_with_condition(product_t *product_information, size_t len_array, char *condition)
 * \breif Вывод массива структур
 * 
 * @param producr_information Указатель на массив структур
 * @param len_array Размер массива структур
 * @param condition Указатель на подстроку 
 * 
 * Данная функция производит вывод структур массива, название предмета которых содержит данную подстроку, 
 * в стандартный поток вывода
*/
int print_with_condition(product_t *product_information, size_t len_array, char *condition);

/**
 * \fn void sort_density_array(product_t *product_information, size_t len_array) 
 * \breif Сортировка массива структур
 * 
 * @param first_product Указатель на структуру массива
 * @param second_product Указатель на структуру массива
 * 
 * Данная функции осуществляет сортировку массива структур по возрастанию плотностей 
*/
void sort_density_array(product_t *product_information, size_t len_array, int (*cmp)(const product_t *, const product_t *));

#endif

