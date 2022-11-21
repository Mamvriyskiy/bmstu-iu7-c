#include <stdio.h>
#include <check.h>
#include <math.h>
#include <string.h>
#include "check_main.h"
#include "product.h"

int cmp_array_struct(product_t *arr1, product_t *arr2, size_t size)
{

    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(arr1[i].name_product, arr2[i].name_product) != 0)
            return NEGATIVE_CMP;
        
        if (fabs(arr1[i].weight - arr2[i].weight) > EPSEL || fabs(arr1[i].volume - arr2[i].volume) > EPSEL)
            return NEGATIVE_CMP;
    }

    return OK;
}


int main()
{
    //PRODUCTR
    Suite *s = product_suite();

    SRunner *runner_s = srunner_create(s);

    srunner_run_all(runner_s, CK_VERBOSE);

    int no_failed = srunner_ntests_failed(runner_s);
    
    srunner_free(runner_s);

    //PRODUCT_ARRAY
    Suite *p = product_array_suite();

    SRunner *runner_p = srunner_create(p);

    srunner_run_all(runner_p, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner_p);
    
    srunner_free(runner_p);

    return no_failed;
}
