#!/bin/bash

# bash ./func_tests/build_gcov.sh
bash ./func_tests/scripts/func_tests.sh 2> ./func_tests/error.txt
# gcov ./src/*.c > gcov.out
# cat gcov.out
bash ./func_tests/clean.sh