#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "polinom_struct.h"
#include "io.h"
#include "allocated.h"
#include "math_operation.h"
#include "work_list.h"

int main()
{
    int error = OK;

    char *type_operation = NULL;

    type_operation = read_type_operation(type_operation);

    if (type_operation == NULL)
        return NEGATIVE_TYPE;

    polinom_t *head = NULL;

    polinom_t *new_head = copy_list(head);
    polinom_free(new_head);

    if (!strcmp(type_operation, "val"))
    {
        error = read_val_polinom(&head);
        if (!error)
        {
            int el;
            if (scanf("%d", &el) == SCANF_ONE_EL_OK)
            {
                int suml = 0;
                error = calculation_polinom(head, el, &suml);
                if (error == OK)
                    printf("%d\n", suml);
            }
        }
    }
    else if (!strcmp(type_operation, "ddx"))
    {
        error = read_val_polinom(&head);
        if (!error)
        {
            polinom_t *tmp = derivative_math(head);
            if (tmp)
                free_list_pos(head, tmp);
            list_print(head);

            printf("L\n");
        }
    }
    else if (!strcmp(type_operation, "sum"))
    {
        error = read_val_polinom(&head);
        if (!error)
        {
            polinom_t *second_head = NULL;
            polinom_t *result = NULL;
            error = read_val_polinom(&second_head);
            if (!error)
            {
                sum_two_polinom(head, second_head, &result);
                if (result)
                {
                    list_print(result);
                    printf("L\n");
                    polinom_free(result);
                }
            }
            if (second_head)
                polinom_free(second_head);
        }
    }
    else if (!strcmp(type_operation, "dvd"))
    {
        error = read_val_polinom(&head);
        if (!error)
        {
            polinom_t *even_list = NULL;
            polinom_t *odd_list = NULL;
            error = split_list(head, &even_list, &odd_list);
            if (error == OK)
            {
                if (even_list)
                {
                    list_print(even_list);
                    printf("L\n");
                    polinom_free(even_list);
                }
                if (odd_list)
                {
                    list_print(odd_list);
                    printf("L\n");
                    polinom_free(odd_list);
                }
            }
        }
    }
    else
        error = NEGATIVE_TYPE;
    

    if (head)
        polinom_free(head);

    free(type_operation);

    return error;
}

