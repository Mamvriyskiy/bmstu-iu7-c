#include <stdio.h>
#include <stdlib.h>
#include "polinom_struct.h"

void polinom_free(polinom_t *head)
{
    polinom_t *tmp;
    for (; head; head = tmp)
    {
        tmp = head->next;
        free(head);
    }
}

void free_list_pos(polinom_t *head, polinom_t *tmp)
{
    polinom_t *cur = head;
    for (; cur->next != tmp; cur = cur->next);

    polinom_free(cur->next);

    cur->next = NULL;

    
}
