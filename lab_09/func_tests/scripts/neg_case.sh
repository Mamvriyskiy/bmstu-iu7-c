#!/bin/bash

name_file=$1

args="$(cat ./func_tests/data/$name_file)"

if [ "$USE_VALGRIND" -eq 1 ]; then
    echo "$args" | xargs valgrind --leak-check=full --quiet --log-file=./out/log.txt --quiet ./app.exe > ./out/tmp.txt
    if [ -s ./out/log.txt ]; then
        memory=0
    else
        memory=1
    fi
fi

c=$(expr "$name_file" : '\(......\)')

if [[ ! -f "./func_tests/data/""$name_file""" ]]; then
	exit 6
fi

if [[ ! -f "./func_tests/data/""$c""_out.txt" ]]; then
	exit 7
fi

if [[ ! -f "./func_tests/data/""$c""_data.txt" ]]; then
	exit 8
fi

echo "$(cat ./func_tests/data/"$c"_args.txt)" | xargs ./app.exe > ./func_tests/output.txt
bash ./func_tests/scripts/comparator.sh "./func_tests/data/""$c""_out.txt" ./func_tests/output.txt $?

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



