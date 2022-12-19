#ifndef _POLINOM_STRUCT_H_
#define _POLINOM_STRUCT_H_


typedef struct polinom
{
    int mult;
    int degree;
    struct polinom *next;
} polinom_t;


#endif
