#include <stdio.h>
#include <math.h>
#include "errors.h"
#include "math_operation.h"
#include "polinom_struct.h"
#include "work_list.h"
#include "io.h"
#include "allocated.h"

int calculation_polinom(polinom_t *head, int el, int *suml)
{
    polinom_t *cur = head;
    if (!cur)
        return NULL_POINTER;

    //обход элементов полинома
    for (; cur != NULL; cur = cur->next)
        (*suml) += cur->mult * (int)pow(el, cur->degree); //умножение коэффицента на элемент, возведенного в степень, добавление полученного вычисления в сумму
                                            
    return OK;
} 

polinom_t *derivative_math(polinom_t *head)
{
    polinom_t *cur = head;

    //обход элементов полинома
    for (; cur != NULL; cur = cur->next)
    {
        if (cur->degree > 0)
        {
            cur->mult *= cur->degree; //домножаем коэффицент полинома на степень
            cur->degree--; //уменьшаем степень
        }
        else 
            return cur;
    }

    return NULL;
}

int sum_two_polinom(polinom_t *head, polinom_t *second_head, polinom_t **result)
{
    polinom_t *cur = head, *s_cur = second_head;
    if (cur == NULL || s_cur == NULL)
        return NULL_POINTER;
    
    //Пока оба полинома не равны NULL
    while (cur != NULL && s_cur != NULL)
    {
        int mult, degree;
        //Если степень первого полинома больше или второй полином равен NULL
        if (cur->degree > s_cur->degree || s_cur == NULL)
        {
            mult = cur->mult;
            degree = cur->degree;
            cur = cur->next;
        }
        else if (cur->degree < s_cur->degree || cur == NULL) 
        {
            //Если степень второго полинома больше или первый полином равен NULL
            mult = s_cur->mult;
            degree = s_cur->degree;
            s_cur = s_cur->next;
        } 
        else 
        {
            mult = s_cur->mult + cur->mult; //сложение коэффицентов полинома 
            degree = cur->degree; //степень элемента полинома
            s_cur = s_cur->next;
            cur = cur->next;
        }
        
        polinom_t *tmp = polinom_create(mult, degree); //создание нового элемента полинома
        if (tmp == NULL)
            return NEGATIVE_ALLOC;

        *result = push_list_back(*result, tmp); //добавление нового элемента полинома в новый полином
    }
    return OK;
}

int split_list(polinom_t *head, polinom_t **even_list, polinom_t **odd_list)
{
    polinom_t *cur = head;
    if (cur == NULL)
        return NULL_POINTER;

    //Обход элементов полинома
    for (; cur != NULL; cur = cur->next) 
    {
        polinom_t *tmp = polinom_create(cur->mult, cur->degree); //создание нового элемента 
        if (tmp == NULL)
                return NEGATIVE_ALLOC;

        //Если степень четная, то закдываем элемент в полином четных степеней, иначе в полином нечетных
        if (cur->degree % 2 == 0)   
            *even_list = push_list_back(*even_list, tmp);
        else
            *odd_list = push_list_back(*odd_list, tmp);
    }

    return OK;
}
