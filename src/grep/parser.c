#include "parser.h"

int ParserFlags(int argc, char** argv, GrepFlagsStruct* flags, char** patterns,
                int* count_patterns) {
  opterr = 0;
  int result;
  int parsing = 1;
  while ((result = getopt(argc, argv, CHECK_FLAGS)) != -1 && parsing) {
    switch (result) {
      case 'e':
        flags->flag_e = 1;
        (*count_patterns)++;
        *patterns = ToGetPatterns(*count_patterns, *patterns, optarg);
        if (patterns == NULL) {
          parsing = 0;
        }
        break;
      case 'v':;
        flags->flag_v = 1;
        break;
      case 'i':
        flags->flag_i = 1;
        break;
      case 'l':
        flags->flag_l = 1;
        break;
      case 'c':
        flags->flag_c = 1;
        break;
      case 'n':
        flags->flag_n = 1;
        break;
      case 'h':
        flags->flag_h = 1;
        break;
      case 's':
        flags->flag_s = 1;
        break;
      case 'f':
        flags->flag_f = 1;
        *patterns = ReadStringFromFile(count_patterns, *patterns, flags);
        if (patterns == NULL) {
          parsing = 0;
        }
        break;
      case 'o':
        flags->flag_o = 1;
        break;
      default:
        parsing = 0;
        ErrorInvalidOption();
    }
  }
  return parsing;
}

char* ToGetPatterns(int count_patterns, char* patterns, char* string) {
  if (count_patterns == 1) {
    patterns = (char*)malloc((strlen(string) + 1) * sizeof(char));
    if (patterns != NULL) {
      patterns[0] = '\0';
    }
  } else {
    patterns = (char*)realloc(
        patterns, (strlen(patterns) + strlen(string) + 2) * sizeof(char));
    if (patterns != NULL) {
      strcat(patterns, "|");
    }
  }
  if (patterns != NULL) {
    strcat(patterns, string);
  } else {
    ErrorMemmoryAllocate();
  }
  return patterns;
}

char* ReadStringFromFile(int* count_patterns, char* patterns,
                         GrepFlagsStruct* flags) {
  FILE* pFile = NULL;
  char buf[BUFFER_SIZE] = {0};
  if ((pFile = fopen(optarg, "r")) != NULL) {
    while ((fgets(buf, BUFFER_SIZE, pFile)) != NULL) {
      if (buf[strlen(buf) - 1] == '\n') {
        buf[strlen(buf) - 1] = '\0';
      }
      (*count_patterns)++;
      if (flags->flag_o && !(flags->flag_c || flags->flag_l)) {
        if (*buf != '\0') {
          char* istr = NULL;
          istr = strtok(buf, SEP);
          char word[BUFFER_SIZE] = {0};
          if (*word != '\0') {
            patterns = ToGetPatterns(*count_patterns, patterns, word);
          }
          while (istr != NULL) {
            strcpy(word, istr);
            if (word[strlen(word) - 1] == '\n') {
              word[strlen(word) - 1] = '\0';
            }
            patterns = ToGetPatterns(*count_patterns, patterns, word);
            istr = strtok(NULL, SEP);
          }
        }
      } else {
        if (*buf == '\0') {
          patterns = ToGetPatterns(*count_patterns, patterns, ".");
        } else {
          patterns = ToGetPatterns(*count_patterns, patterns, buf);
        }
      }
    }
    fclose(pFile);
  } else {
    ErrorNoSuchFile(optarg);
  }
  return patterns;
}
