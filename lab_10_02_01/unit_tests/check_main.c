#include <check.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "check_main.h"
#include "polinom_struct.h"
#include "errors.h"
#include "work_list.h"

int make_list(polinom_t **head, int *arr, size_t n)
{
    int error = OK;
    for (size_t i = 0; i < n; i += 2)
    {
        polinom_t *tmp = polinom_create(arr[i], arr[i + 1]);
        if (tmp)
            *head = push_list_back(*head, tmp);
        else 
            error = NEGATIVE_ALLOC;
    }

    return error;
}


int compare_list(polinom_t *list_1, polinom_t *list_2)
{
    while (list_1 != NULL)
    {
        if (list_1->mult != list_2->mult || list_1->degree != list_2->degree)
            return NEGATIVE_TEST;

        list_1 = list_1->next;
        list_2 = list_2->next;
    }

    return OK;
}

int main()
{
    //CHECK_WORK_LIST
    Suite *s = math_op_suite();

    SRunner *runner_s = srunner_create(s);

    srunner_run_all(runner_s, CK_VERBOSE);

    int no_failed = srunner_ntests_failed(runner_s);
    
    srunner_free(runner_s);

    Suite *p = work_list_suite();

    SRunner *runner_p = srunner_create(p);

    srunner_run_all(runner_p, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner_p);
    
    srunner_free(runner_p);

    return no_failed;

}




