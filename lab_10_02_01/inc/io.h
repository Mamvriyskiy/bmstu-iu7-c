#ifndef _IO_H_
#define _IO_H_

#include "polinom_struct.h"

#define MAX_LEN_TYPE 4

/**
 * Чтение строки
 * 
 * Данная функция осуществляет чтение типа операции
 */
char *read_type_operation();

/**
 * Чтение списка
 * 
 * @param [out] head Указатель на указатель на начало списка
 * 
 * Данная функция осуществялет чтение полинома с заполнением списка
 */
int read_val_polinom(polinom_t **head);

/**
 * Вывод списка
 * 
 * @param [in] head Указатель на начало списка
 * 
 * Данная функция осуществялет вывод полинома на экран
 */
void list_print(const polinom_t *head);

/**
 * Вывод данных элемента списка
 * 
 * @param [in] tmp Указатель на начало списка
 * 
 * Данная функция осуществялет выводданных элемента списка
 */
void polinom_el_print(const polinom_t *tmp);

#endif

