#!/bin/bash

gcc -std=c99 -Wall -Werror -O0 --coverage ./*.c -o app.exe -lm