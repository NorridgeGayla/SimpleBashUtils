#include "../headers/parser.h"

int ParserFlags(int argc, char **argv, CatFlagsStruct *flags) {
  static struct option gnu_flags[] = {{"number-nonblank", 0, 0, 'b'},
                                      {"number", 0, 0, 'n'},
                                      {"squeeze-blank", 0, 0, 's'},
                                      {0, 0, 0, 0}};
  opterr = 0;
  int result;
  int option_index = 0;
  int parsing = 1;
  while ((result = getopt_long(argc, argv, CHECK_FLAGS, gnu_flags,
                               &option_index)) != -1 &&
         parsing) {
    switch (result) {
      case 'b':
        flags->flag_b = 1;
        break;
      case 'e':
        flags->flag_e = 1;
        flags->flag_v = 1;
        break;
      case 'E':
        flags->flag_E = 1;
        break;
      case 'n':
        flags->flag_n = 1;
        break;
      case 's':
        flags->flag_s = 1;
        break;
      case 't':
        flags->flag_t = 1;
        flags->flag_v = 1;
        break;
      case 'T':
        flags->flag_T = 1;
        break;
      case 'v':
        flags->flag_v = 1;
        break;
      default:
        parsing = 0;
        ErrorInvalidOption();
    }
  }
  return parsing;
}
