CC := gcc
FLAGS := -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -pedantic
U_FLAGS := -lcheck -lpthread -lrt -lm
FUNC_VLG :=

SRC_DIR := ./src
INC_DIR := ./inc
UNIT_DIR := ./unit_tests
OBJ_DIR := ./out

SRC := $(wildcard $(SRC_DIR)/*.c)
INC := $(wildcard $(INC_DIR)/*.h)
UNITS := $(wildcard $(UNIT_DIR)/*.c)

OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_UNIT := $(patsubst $(UNIT_DIR)/%.c, $(OBJ_DIR)/%.o, $(UNITS))
OBJ_UNIT += $(filter-out $(OBJ_DIR)/main.o, $(OBJ))
INC_HD := -I$(INC_DIR)

APP = app.exe
UNIT_TEST = unit_tests.exe

$(APP) : $(OBJ)
	$(CC) $(OBJ) -o $@

$(UNIT_TEST) : $(OBJ_UNIT)
	$(CC) $(OBJ_UNIT) -o $@ $(U_FLAGS)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC) $(OBJ_DIR)
	$(CC) $(INC_HD) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(UNIT_DIR)/%.c $(INC) $(OBJ_DIR)
	$(CC) $(INC_HD) $(FLAGS) $(U_FLAGS) -c $< -o $@

.PHONY : clean func unit release debug

release : $(APP)
release : FLAGS += -DNDEBUG -g0

debug : $(APP)
debug : FLAGS += -g3

ifeq ($(USE_VLG), 1)
FUNC_FLAGS += --valgrind
endif

unit: $(UNIT_TEST)
	./$(UNIT_TEST)

clean:
	rm -rf $(OBJ_DIR) *.exe *.txt ./func_tests/*.txt *.out;
 
func : 
	./func_tests/scripts/func_tests.sh $(FUNC_FLAGS)
