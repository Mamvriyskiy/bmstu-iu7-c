#ifndef _SEARCH_SQUARE_H_
#define _SEARCH_SQUARE_H_

#define EPS 0.0000001
#define NEW_LEN 1
#define OK 0

/**
 * Получение длины массива
 * 
 * @param [in] array Указатель на начало массива
 * @param [in] lenl Длина массива
 * 
 * Данная функция осуществляет подсчет количества элементов, удовлетворяющих условию
 */
size_t create_len(const int *array, const size_t lenl);

/**
 * Проверка на полный квадрат
 * 
 * @param [in] num Указатель на начало массива
 * 
 * Данная функция осуществляет проверку элемента на полный квадрат
 */
int check_square(int num);

/**
 * Поиск полных квадратов
 * 
 * @param [in] array Указатель на начало массива
 * @param [in] lenl Длина массива
 * @param [out] tmp Указатель на начало массива
 * @param [inout] tmp_lenl Длина массива
 * 
 * Данная функция осуществляет поиск полных квадратов, заполняет ими массив
 */
int filter(const int *array, const size_t lenl, int *tmp, size_t *tmp_lenl);

#endif
