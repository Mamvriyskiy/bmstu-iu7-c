#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#define EPS 0.0000001

typedef struct
{
    char *name_product;
    float weight;
    float volume;
} product_t;

/**
 * Чтение структуры из файла
 * 
 * @param [in] file Указатель на файл
 * @param [out] current_struct Указатель на структуру массива
 * @param [out] weight Указатель на массу
 * @param [out] volume Указатель на объем
 * @param [out] buf Указатель на название предмета
 * 
 * Данная функции осуществлет чтение структуры из файла с заполнением массива структур
*/
int read_subject(FILE *file, double *weight, double *volume, char *buf);

/**
 * Вывод структур массива
 * 
 * @param [in] product Указатель на структуру массива
 * 
 * Данная функция выводит данные из структуры в стандартный поток вывода
*/
void print_inpformation(product_t *product);

/**
 * Подсчет разности плотностей предметов
 * 
 * @param [in] first_product Указатель на структуру массива
 * @param [in] second_product Указатель на структуру массива
 * 
 * Данная функции производит подсчет плотности каждого из предметов, с последующим нахожденим 
 * разности этих плотностей
*/
int difference_disteny_product(const product_t *first_product, const product_t *second_product);

/**
 * Перестановка структур массива местами
 * 
 * @param [out] first_product Указатель на структуру массива
 * @param [out] second_product Указатель на структуру массива
 * 
 * Данная функции менятет местами соответствующие структуры массива
*/
void swap_product(product_t *first_product, product_t *second_product);

#endif
