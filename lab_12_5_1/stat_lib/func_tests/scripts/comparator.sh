#!/bin/bash

file_1="$1"
file_2="$2"
el="$3"

if [ "$el" -ne 0 ]; then
	exit 0
fi

if [ -z "$(diff "$file_1" "$file_2")" ]; then
	exit 0
else
	exit 1
fi
