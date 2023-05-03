TARGET = my_cat
CC = gcc 
FLAGS = -Wall -Werror -Wextra -pedantic -std=c11

SRC_DIR = ./sources
HDR_DIR = ./headers
COM_DIR = ../common
TEST_DIR = ./test
BUILD_DIR = ../../build

SRC_CAT = $(SRC_DIR)/*.c $(COM_DIR)/*.c
OBJ_CAT = $(SRC_CAT: .c=.o)

all: clean $(TARGET)

$(TARGET): $(OBJ_CAT)
	$(CC) -g $(FLAGS) $(OBJ_CAT) -o $(BUILD_DIR)/$(TARGET)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: test
test:
	chmod +x $(TEST_DIR)/t_cat.sh
	bash $(TEST_DIR)/t_cat.sh

check:
	clang-format -n $(SRC_DIR)/*.c $(HDR_DIR)/*.h

leaks:
	valgrind --leak-check=full --leak-resolution=low --quiet --log-file=$(TEST_DIR)/leaks.txt $(BUILD_DIR)/$(TARGET) $(TEST_DIR)/bytes.txt

rebuild: clean $(TARGET)

clean:
	rm -f $(BUILD_DIR)/$(TARGET)
	rm -f $(TEST_DIR)/log.txt
	rm -f $(TEST_DIR)/leaks.txt