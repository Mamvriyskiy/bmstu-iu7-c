CFLAGS := -std=c99 -Wall -Werror -pedantic

.PHONY: func clean unit

# app.exe : ./out/main.o ./out/filter_array.o ./out/work_file.o ./out/sort_array.o
# 	gcc $(CFLAGS) $^ -o $@

unit_test.exe : ./out/check_filter_array.o ./out/check_main.o ./out/check_sort_array.o
	gcc $(CFLAGS)  -c $^ -o $@ -lcheck -lpthread -lrt -lsubunit -lm

./out/%.o: ./src/%.c ./inc/*.h ./out
	gcc $(CFLAGS) -c $< -o $@

./out/%.o: ./unit_tests/%.c ./inc/check_main.h ./out
	gcc $(CFLAGS) -c $< -o $@


clean: 
	rm -f ./out/*.o *.exe ./out/*.gcno *.o *.gcno