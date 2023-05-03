#include "s21_grep.h"

#include "../common/error.h"
#include "parser.h"
#include "reader.h"

int main(int argc, char** argv) {
  S21Grep(argc, argv);
  return 0;
}

void S21Grep(int argc, char** argv) {
  if (argc > 2) {
    GrepFlagsStruct flags = {0};
    char* patterns = NULL;
    int count_patterns = 0;
    int check = ParserFlags(argc, argv, &flags, &patterns, &count_patterns);
    if (check) {
      patterns = OpenFile(argc, argv, &flags, patterns, &count_patterns);
    }
    if (patterns != NULL) {
      free(patterns);
    }
  } else {
    ErrorNotArgumets();
  }
}
