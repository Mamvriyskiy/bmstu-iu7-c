#!/bin/bash

name_file=$1
if [ "$USE_VALGRIND" -eq 1 ]; then
    valgrind --leak-check=full --log-file=log.txt --quiet ./app.exe < ./func_tests/data/"$name_file" > /dev/null
    if [ -s log.txt ]; then
        memory=0
    else
        memory=1
    fi
fi

c=$(expr "$name_file" : '\(......\)')

./app.exe < func_tests/data/"$name_file" > ./func_tests/output.txt
bash ./func_tests/scripts/comparator.sh "./func_tests/data/""$c""_out.txt" ./func_tests/output.txt

exit_code="$?"

if [ "$USE_VALGRIND" -eq 1 ]; then 
	if [ "$memory" -eq 1 ]; then 
		if [ "$exit_code" -eq 0 ]; then 
			exit 2 
		else 
			exit 3
		fi
	else
		if [ "$exit_code" -eq 0 ]; then 
			exit 4
		else 
			exit 5
		fi
	fi
else 
	exit "$exit_code"
fi
