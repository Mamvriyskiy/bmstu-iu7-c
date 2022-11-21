#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include "product.h"

#define NEGATIVE_CMP -1
#define OK 0
#define NEGATIVE_SIZE_ARRAY -2

#define EPSEL 0.0000001

/**
 * Сравнение массивов структур
 * 
 * @param [in] arr1 Указатель на начло массива структур
 * @param [in] arr2 Указатель на начало массива структур
 * @param [in] size Размерность массива стурктур
 * 
 * Данная функция производит сравнение двух массивов структур поэлементно 
*/
int cmp_array_struct(product_t *arr1, product_t *arr2, size_t size);

Suite *product_suite();
Suite *product_array_suite();

#endif
