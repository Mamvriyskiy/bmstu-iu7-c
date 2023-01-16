#include <stdio.h>
#include <check.h>
#include "check_main.h"

int main()
{
    Suite *s = filter_suite();

    SRunner *runner_s = srunner_create(s);

    srunner_run_all(runner_s, CK_VERBOSE);

    int no_failed = srunner_ntests_failed(runner_s);
    
    srunner_free(runner_s);

    Suite *p = shift_suite();

    SRunner *runner_p = srunner_create(p);

    srunner_run_all(runner_p, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner_p);
    
    srunner_free(runner_p);

    return no_failed;
}
