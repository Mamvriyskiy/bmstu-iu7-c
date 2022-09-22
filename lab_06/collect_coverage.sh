#!/bin/bash

bash build_gcov.sh
bash ./func_tests/scripts/func_tests.sh 2> error.txt
gcov ./*.c > gcov.out
cat gcov.out