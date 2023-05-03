TARGET = my_grep
CC = gcc
FLAGS = -Wall -Werror -Wextra -pedantic -std=c11

SRC_DIR = ./sources
HDR_DIR = ./headers
COM_DIR = ../common
TEST_DIR = ./test
BUILD_DIR = ../../build

SRC_GREP = $(SRC_DIR)/*.c $(COM_DIR)/*.c
OBJ_GREP = $(SRC_GREP: .c=.o)

all: clean $(TARGET)

$(TARGET): $(OBJ_GREP)
	$(CC) -g $(FLAGS) $(OBJ_GREP) -o $(BUILD_DIR)/$(TARGET)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: test
test:
	chmod +x $(TEST_DIR)/grep_test.sh
	bash $(TEST_DIR)/grep_test.sh

check:
	clang-format -n $(SRC_DIR)/*.c $(HDR_DIR)/*.h

leaks:
	valgrind --leak-check=full --leak-resolution=low --quiet --log-file=$(TEST_DIR)/leaks.txt $(BUILD_DIR)/$(TARGET) -n -f $(TEST_DIR)/file.txt -e Hello $(TEST_DIR)/test.txt $(TEST_DIR)/test2.txt test3.txt

rebuild: clean $(TARGET)

clean:
	rm -f $(BUILD_DIR)/$(TARGET)
	rm -f $(TEST_DIR)/log.txt
	rm -f $(TEST_DIR)/leaks.txt