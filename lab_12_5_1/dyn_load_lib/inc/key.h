#ifndef _KEY_H_
#define _KEY_H_

/**
 * Создание новго массива с помощью фильтра
 * 
 * @param [out] pb_src Указатель на начало массива
 * @param [in] pe_src Указатель за конец массива
 * @param [in] pb_dst Указатель на начало массива
 * @param [in] pe_dst Указатель за конец массива
 * 
 * Данная функция осуществляет заполнение массива целыми числами с помощью фильтра
*/
int key(const int *pb_src, const int *pe_src, int *pb_dst, long long int suml);

/**
 * Подсчет суммы элементов массива
 * 
 * @param [in] pb_src Указатель на начало массива
 * @param [in] pe_src Указатель за конец массива
 * 
 * Данная функция осуществляет подсчет суммы элементов массива целых чисел
*/
long long int create_sum(const int *pb_src, const int *pe_src);

/**
 * Подсчет количества элементов, удовлетворяющие фильтр
 * 
 * @param [in] pb_src Указатель на начало массива
 * @param [in] pe_src Указатель за конец массива
 * @param [in] suml Сумма элементов массива 
 * 
 * Данная функция осуществляет подсчет количества целых чисел, удовлетворяющих условие фильтра
*/
size_t count_correct_element(const int *pb_src, const int *pe_src, long long int suml);

/**
 * Заполнение массива элементами 
 * 
 * @param [out] pb_src Указатель на начало массива
 * @param [in] pe_src Указатель за конец массива
 * @param [in] pb_tmp Указатель на начало массива
 * @param [in] suml Сумма элементов массива 
 * 
 * Данная функция осуществляет заполнение массива целыми числами, удовлетворяющих условие фильтра
*/
void search_right_element(const int *pb_src, const int *pe_src, int *pb_tmp, long long int suml);

#endif
