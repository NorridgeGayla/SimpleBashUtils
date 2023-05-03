#include "../headers/my_grep.h"

#include "../../common/error.h"
#include "../headers/parser.h"
#include "../headers/reader.h"

int main(int argc, char** argv) {
  my_grep(argc, argv);
  return 0;
}

void my_grep(int argc, char** argv) {
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
