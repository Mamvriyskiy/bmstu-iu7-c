#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdio.h>

#define TITLE_LEN 25

typedef struct
{
    char name_product[TITLE_LEN + 1];
    float weight;
    float volume;
} product_t;

/**
 * \fn int read_subject(FILE *file, product_t *current_struct)
 * \breif Cчитывание структуры из файла
 * 
 * @param file Поток ввода
 * @param current_struct Указатель на структуру
 * 
 * Данная функции производит считывание стрктуры из потока ввода
*/
int read_subject(FILE *file, product_t *current_struct);

/**
 * \fn void print_inpformation(product_t *product)
 * \breif Вывод структур массива
 * 
 * @param product Указатель на структуру массива
 * 
 * Данная функция выводит данные из структуры в стандартный поток вывода
*/
void print_inpformation(product_t *product);

/**
 * \fn float difference_disteny_product(product_t *first_product, product_t *second_product)
 * \breif Подсчет разности плотностей предметов
 * 
 * @param first_product Указатель на структуру массива
 * @param second_product Указатель на структуру массива
 * 
 * Данная функции производит подсчет плотности каждого из предметов, с последующим нахожденим 
 * разности этих плотностей
*/
int difference_disteny_product(const product_t *first_product, const product_t *second_product);

/**
 * \fn void swap_product(product_t *first_product, product_t *second_product)
 * \breif Перестановка структур массива местами
 * 
 * @param first_product Указатель на структуру массива
 * @param second_product Указатель на структуру массива
 * 
 * Данная функции менятет местами соответствующие структуры массива
*/
void swap_product(product_t *first_product, product_t *second_product);

#endif
