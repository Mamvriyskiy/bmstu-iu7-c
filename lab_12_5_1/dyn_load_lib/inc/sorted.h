#ifndef _SORTED_H_
#define _SORTED_H_

/**
 * Сортировка массива целых чисел
 * 
 * @param [in] pb Указатель на начало массива
 * @param [in] n Размер массива
 * @param [in] size Размер одного элемента
 * @param [in] cmp Указатель на функцию
 * 
 * Данная функция осуществляет сортировку массива целых чисел по возрастанию 
*/
void mysort(void *pb, size_t n, size_t size, int (*cmp)(const void *, const void *));


/**
 * Разность двух чисел
 * 
 * @param [in] first_el Указатель на элемент
 * @param [in] second_el Указатель на элемент
 * 
 * Данная функция осуществляет вычитание второго числа из первого
*/
int compare(const void *first_el, const void *second_el);

/**
 * Перестановка целых чисел массива местами
 * 
 * @param [out] first_el Указатель на элемент
 * @param [out] second_el Указатель на элемент
 * @param [in] size Размер одного элемента
 * 
 * Данная функция меняет местами соответствующие структуры массива
*/
void swap_el(void *first_el, void *second_el, size_t lenl);

#endif
