#ifndef _ALLOCATED_H_
#define _ALLOCATED_H_

#include "polinom_struct.h"

/**
 * Освобождение памяти
 * 
 * @param [out] head Указатель на начало списка
 * 
 * Данная функция осуществляет освобождение памяти из-под списка
 */
void polinom_free(polinom_t *head);

void free_list_pos(polinom_t *head, polinom_t *tmp);

#endif
