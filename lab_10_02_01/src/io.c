#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "polinom_struct.h"
#include "errors.h"
#include "work_list.h"

char *read_type_operation()
{
    ssize_t read;
    size_t len;

    char *type_op = NULL;

    read = getline(&type_op, &len, stdin);
    if (read == -1 || type_op == NULL)
        return NULL;

    type_op[read - 1] = '\0';


    return type_op;
}

int read_val_polinom(polinom_t **head)
{
    int error = OK;
    while (error == OK)
    {
        int mult, degree;
        char el;
        if (scanf("%d%c", &mult, &el) == 2)
        {
            if (el != '\n' && scanf("%d%c", &degree, &el) == 2)
            {
                polinom_t *tmp = polinom_create(mult, degree);
                if (tmp == NULL)
                    return NEGATIVE_ALLOC;
                
                *head = push_list_back(*head, tmp);
                if (el == '\n')
                    break;
            }
            else 
                error = NEGATIVE_READ;
        }
        else
            error = NEGATIVE_READ;
    }

    return error;
}

void list_print(const polinom_t *head)
{
    for (const polinom_t *cur = head; cur != NULL; cur = cur->next)
    {
        polinom_el_print(cur);
    }
}

void polinom_el_print(const polinom_t *tmp)
{
    printf("%d %d ", tmp->mult, tmp->degree);
}
