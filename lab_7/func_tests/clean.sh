#!/bin/bash

# rm -f main.c.gcov
# rm -f gcov.out
# rm -f a.out
# rm -f main.o
# rm -f main.gcda
# rm -f main.gcno
# rm -f app.exe
# rm -f func_tests/data/out_1.txt
# rm -f func_tests/scripts/log.txt 
# rm -f output.txt
# rm -f func_tests/data/out.txt
# rm -f func.c.gcov
# rm -f func.gcda
# rm -f func.gcno
# rm -f func.o
# rm -f func_tests/scripts/error.txt
# rm -f work_array.c.gcov
# rm -f work_array.o
# rm -f work_file.c.gcov
# rm -f work_file.o
# rm -f pwork_array.gcda
# rm -f work_file.gcda
# rm -f ./func_tests/error.txt
# rm -f ./func_tests/output.txt

for (( j = 8; j < 9; j++ )); do
    touch data/"pos_0"$j"_args.txt"
    touch data/"pos_0"$j"_int.txt"
    touch data/"pos_0"$j"_data.txt"
    touch data/"pos_0"$j"_out.txt"
done