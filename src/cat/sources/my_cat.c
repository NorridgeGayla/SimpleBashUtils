#include "../headers/my_cat.h"

#include "../../common/error.h"
#include "../headers//reader.h"
#include "../headers/parser.h"

int main(int argc, char** argv) {
  my_cat(argc, argv);
  return 0;
}

void my_cat(int argc, char** argv) {
  if (argc > 1) {
    CatFlagsStruct flags = {0};
    int check = ParserFlags(argc, argv, &flags);
    if (check) {
      RunSomeCatFunc(argc, argv, &flags);
    }
  } else {
    ErrorNotArgumets();
  }
}
