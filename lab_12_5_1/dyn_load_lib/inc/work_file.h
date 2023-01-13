#ifndef _WORK_FILE_H_
#define _WORK_FILE_H_

/**
 * Подсчет количества чисел в файле
 * 
 * @param [in] file Поток ввода
 * @param [out] count Указатель на количество чисел
 * 
 * Данная функция производит подсчет количества целых чисел в файла
*/
int count_quantity_number(FILE *file, size_t *count);

/**
 * Запись целых чисел в массив из файла
 * 
 * @param [in] file Поток ввода
 * @param [out] pb Указатель на начало массива
 * @param [in] pe Указатель за конец массива
 * 
 * Данная функция производит считывание целых чисел из файла и записывает их в массив
*/
int read_number_from_file(FILE *file, int *pb, int *pe);

/**
 * Запись массива целых чисел в файл
 * 
 * @param [in] name_file Имя файла
 * @param [out] pb Указатель на начало массива
 * @param [in] pe Указатель за конец массива
 * 
 * Данная функция осуществляет вывод массива целых чисел в файл
*/
int fill_file(char *name_file, const int *pb, const int *pe);

#endif
