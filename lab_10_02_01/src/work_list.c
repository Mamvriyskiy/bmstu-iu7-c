#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "work_list.h"
#include "polinom_struct.h"
#include "allocated.h"
#include "io.h"


polinom_t *copy_list(polinom_t *head)
{
    if (!head)
        return NULL;

    polinom_t *cur = head;

    polinom_t *new_head = NULL, *node_tmp = NULL;

    for (; cur; cur = cur->next)
    {
        polinom_t *tmp = list_create_el(cur->mult, cur->degree);
        if (!tmp)
        {
            polinom_free(new_head);
            return NULL;
        }

        if (!new_head)
            new_head = tmp;
        else
            node_tmp->next = tmp;

        node_tmp = tmp;
    }

    return new_head;
}

polinom_t *list_create_el(int mult, int degree)
{
    polinom_t *tmp = malloc(sizeof(polinom_t));
    if (!tmp)
        return NULL;

    tmp->next = NULL;
    tmp->mult = mult;
    tmp->degree = degree;

    return tmp;
}


polinom_t *push_list_back(polinom_t *head, polinom_t *pnode)
{
    polinom_t *cur = head;

    if (cur == NULL)
    {
        head = pnode;
        return head;
    }

    while (cur->next != NULL)
        cur = cur->next;

    cur->next = pnode;

    return head;
}

polinom_t *polinom_create(int mult, int degree)
{
    polinom_t *tmp;
    tmp = malloc(sizeof(polinom_t));

    if (!tmp)
        return NULL;
    else
    {
        tmp->mult = mult;
        tmp->degree = degree;
        tmp->next = NULL;
        return tmp;
    }
}

