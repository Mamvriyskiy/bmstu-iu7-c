#ifndef _SHIFT_H_
#define _SHIFT_H_

/**
 * Циклический сдвиг влево
 * 
 * @param [out] array Указатель на начало массива
 * @param [in] lenl Длина массива
 * @param [in] k Количество сдвигов
 * 
 * Данная функция осуществляет циклический сдвиг элементов массива влево
 */
void shift(int *array, const size_t lenl, size_t k);

#endif
