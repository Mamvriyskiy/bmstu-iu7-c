#!/bin/bash

file_1="$1"
file_2="$2"

diff "$file_1" "$file_2"

if [ -z "$(diff "$file_1" "$file_2")" ]; then
	exit 0
else
	exit 1
fi
