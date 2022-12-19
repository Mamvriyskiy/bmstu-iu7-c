#ifndef _WORK_LIST_H_
#define _WORK_LIST_H_

#include "polinom_struct.h"

/**
 * Вставка элемента списка
 * 
 * @param [inout] head Указатель на начало списка
 * @param [in] pnode Указатель на новый элемент списка
 * 
 * Функция осуществляет вставку элемента списка в конец списка
 */
polinom_t *push_list_back(polinom_t *head, polinom_t *pnode);

/**
 * Создание элемента списка
 * 
 * @param [in] mult Элемент
 * @param [in] degree Степень
 * 
 * Данная функция осуществляет создание элемента полинома
 */
polinom_t *polinom_create(int mult, int degree);

polinom_t *list_create_el(int mult, int degree);

polinom_t *copy_list(polinom_t *head);

#endif
