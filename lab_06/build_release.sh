#!/bin/bash

gcc -std=c99 -Wall -Werror -c ./*.c 
gcc -o app.exe ./*.o -lm