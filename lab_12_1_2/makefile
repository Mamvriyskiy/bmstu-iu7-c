CC := gcc
FLAGS := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion
U_FLAGS := -lcheck -lpthread -lrt -lm -lsubunit
FUNC_VLG :=

SRC_DIR := ./src
INC_DIR := ./inc
UNIT_DIR := ./unit_tests
OBJ_DIR := ./out

SRC := $(wildcard $(SRC_DIR)/*.c)
INC := $(wildcard $(INC_DIR)/*.h)
UNITS := $(wildcard $(UNIT_DIR)/*.c)

SRC := $(filter-out $(SRC_DIR)/main.c, $(SRC))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_UNIT := $(patsubst $(UNIT_DIR)/%.c, $(OBJ_DIR)/%.o, $(UNITS))
# OBJ_UNIT += $(filter-out $(OBJ_DIR)/main.o, $(OBJ))

INC_HD := -I$(INC_DIR)

LIB := libarr.so
APP = app.exe
UNIT_TEST = unit_tests.exe

$(LIB) : $(OBJ)
	$(CC) -shared $^ -o $@

$(UNIT_TEST) : $(OBJ_UNIT) $(LIB)
	$(CC) -Iinc $(OBJ_UNIT) -o $@ $(U_FLAGS) -ldl

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o : $(UNIT_DIR)/%.c $(INC) $(OBJ_DIR)
	$(CC) $(INC_HD) $(FLAGS) $(U_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC) $(OBJ_DIR)
	$(CC) $(INC_HD) $(FLAGS) -c $< -o $@

.PHONY : clean func unit release debug


unit: $(UNIT_TEST)
	./$(UNIT_TEST)

clean:
	rm -rf $(OBJ_DIR) *.exe *.txt ./func_tests/*.txt *.a *.so;
 
run: $(LIB)
	@export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.; python3 src/main.py
