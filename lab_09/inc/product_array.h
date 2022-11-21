#ifndef _PRODUCT_ARRAY_H_
#define _PRODUCT_ARRAY_H_

#include "product.h"

/**
 * Создание массива структур
 * 
 * @param [in] name_file Имя файла
 * @param [in] len_array Указатель на размер массива структур
 * @param [inout] array Указатель на указатель на массив структур
 * 
 * Данная функция осуществляет создание массива структур с последующим заполнением
*/
int create_struct_array_ex(char *name_file, size_t *len_array, product_t **array);

/**
 * Подсчет количесвта структур в файле
 * 
 * @param [in] file Указатель на файл
 * @param [out] len_array Указатель на размер массива структур
 * 
 * Данная функция осуществляет подсчет количесвта структур в файле
*/
int count_lenl_array(FILE *file, size_t *len_array);

/**
 * Заполнение массива структур
 * 
 * @param [in] file Указатель на файл
 * @param [out] array Указатель на массив структур
 * @param [in] lenl Размер массива структур
 * 
 * Данная функция осуществляет заполнение массива структур, считывая структуры из файла
*/
int create_array(FILE *file, product_t *array, size_t lenl);

/**
 * Вывод массива структур
 * 
 * @param [in] product_information Указатель на массив структур
 * @param [in] len_array Длина массива структур
 * 
 * Данная функция осуществляет вывод массива структур в стандартный поток вывода
*/
void print_all_array(product_t *product_information, size_t len_array);

/**
 * Освобождение паямти
 * 
 * @param [in] array Указатель на массив структур
 * @param [in] lenl Длина массива структур
 * 
 * Данная функция осуществляет освобождение памяти из-под массива структур
*/
void free_struct(product_t *array, size_t lenl);

/**
 * Сортировка массива структур
 * 
 * @param [in] first_product Указатель на структуру массива
 * @param [in] second_product Указатель на структуру массива
 * 
 * Данная функции осуществляет сортировку массива структур по возрастанию плотностей 
*/
void sort_density_array(product_t *product_information, size_t len_array, int (*cmp)(const product_t *, const product_t *));

/**
 * Вывод массива структур
 * 
 * @param [in] producr_information Указатель на массив структур
 * @param [in] len_array Размер массива структур
 * @param [in] condition Указатель на подстроку 
 * 
 * Данная функция производит вывод структур массива, название предмета которых содержит данную подстроку, 
 * в стандартный поток вывода
*/
int print_with_condition(product_t *product_information, size_t len_array, char *condition);

#endif

