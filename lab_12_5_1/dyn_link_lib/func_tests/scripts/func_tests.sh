#!/bin/bash

valgrind="$1"

if [[ "$valgrind" == "--valgrind" ]]; then
    export USE_VALGRIND=1
else 
    export USE_VALGRIND=0
fi

count_pos_in="$(find ./func_tests/data | grep -c "pos_[0-9][0-9]_args.txt")"
count_neg_in="$(find ./func_tests/data | grep -c "neg_[0-9][0-9]_args.txt")"

echo ""
echo "POSITIVE TESTS: "
for (( i = 1; i < $((count_pos_in + 1)); i++ )); do
    if  [[ $i -lt 10 ]]; then
        a="pos_0""$i""_args.txt"
    else 
        a="pos_""$i""_args.txt"
    fi
    bash ./func_tests/scripts/pos_case.sh "$a"
    exite_code="$?"
    if [ "$exite_code" -eq 0 ]; then
        echo "POSITIVE TEST $i OK"
    elif [ "$exite_code" -eq 1 ]; then
        echo "POSITIVE TEST $i FAILD"
    elif [ "$exite_code" -eq 2 ]; then
        echo "POSITIVE TEST $i OK"
        echo "POSITIVE TEST $i MEMORY OK"
    elif [ "$exite_code" -eq 3 ]; then
        echo "POSITIVE TEST $i FAILD"
        echo "POSITIVE TEST $i MEMORY OK"
    elif [ "$exite_code" -eq 4 ]; then
        echo "POSITIVE TEST $i OK"
        echo "POSITIVE TEST $i MEMORY FAILD"
    elif [ "$exite_code" -eq 5 ]; then
        echo "POSITIVE TEST $i FAILD"
        echo "POSITIVE TEST $i MEMORY FAILD"
    elif [ "$exite_code" -eq 6 ]; then
        echo "NON POS_""$i""_IN.TXT"
    elif [ "$exite_code" -eq 7 ]; then
        echo "NON POS_""$i""_OUT.TXT"
    elif [ "$exite_code" -eq 8 ]; then
        echo "NON POS_""$i""_TEST.TXT"
    fi
done

echo ""
echo "NEGATIVE TESTS:"
for (( j = 1; j < $((count_neg_in + 1)); j++ )); do
    if [[ $j -lt 10 ]]; then
        b="neg_0""$j""_args.txt"
    else 
        b="neg_""$j""_args.txt"
    fi 
    bash ./func_tests/scripts/neg_case.sh "$b"
    exite_code="$?"
    if [ "$exite_code" -eq 0 ]; then
        echo "NEGATIVE TEST $j OK"
    elif [ "$exite_code" -eq 1 ]; then
        echo "NEGATIVE TEST $j FAILD"
    elif [ "$exite_code" -eq 2 ]; then
        echo "NEGATIVE TEST $j OK"
        echo "NEGATIVE TEST $j MEMORY OK"
    elif [ "$exite_code" -eq 3 ]; then
        echo "NEGATIVE TEST $j FAILD"
        echo "NEGATIVE TEST $j MEMORY OK"
    elif [ "$exite_code" -eq 4 ]; then
        echo "NEGATIVE TEST $j OK"
        echo "NEGATIVE TEST $j MEMORY FAILD"
    elif [ "$exite_code" -eq 5 ]; then
        echo "NEGATIVE TEST $j FAILD"
        echo "NEGATIVE TEST $j MEMORY FAILD"
    elif [ "$exite_code" -eq 6 ]; then
        echo "NON NEG_""$i""_IN.TXT"
    elif [ "$exite_code" -eq 7 ]; then
        echo "NON NEG_""$i""_OUT.TXT"
    elif [ "$exite_code" -eq 8 ]; then
        echo "NON NEG_""$i""_TEST.TXT"
    fi
done


