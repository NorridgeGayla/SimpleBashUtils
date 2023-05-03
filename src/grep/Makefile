TARGET = s21_grep
CC = gcc
FLAGS = -Wall -Werror -Wextra
COM_DIR = ../common/

SRC_CAT = $(wildcard *.c $(COM_DIR)*.c)
OBJ_CAT = $(SRC_CAT: .c=.o)

$(TARGET): $(OBJ_CAT)
	$(CC) -g $(FLAGS) $(OBJ_CAT) -o $(TARGET)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

test:
	./$(TARGET) -o -c -f file.txt test.txt test2.txt

check:
	clang-format -i -n *.c *.h

leaks:
	valgrind --leak-check=full ./$(TARGET) -n -f file.txt -e Hello test.txt test2.txt test3.txt

clean:
	rm $(TARGET)