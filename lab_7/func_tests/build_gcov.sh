#!/bin/bash

gcc -std=c99 -Wall -Werror -O0 --coverage ./src/*.c -o app.exe -lm