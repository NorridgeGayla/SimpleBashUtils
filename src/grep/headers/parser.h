#ifndef SIMPLEBASHUTILS_SRC_GREP_HEADERS_PARSER_H_
#define SIMPLEBASHUTILS_SRC_GREP_HEADERS_PARSER_H_

#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#include "../../common/error.h"
#include "my_grep.h"

#define BUFFER_SIZE 4096
#define CHECK_FLAGS "e:vilcnhsf:o"
#define SEP " "

int ParserFlags(int argc, char** argv, GrepFlagsStruct* flags, char** patterns,
                int* count_patterns);
char* ToGetPatterns(int count, char* patterns, char* string);
char* ReadStringFromFile(int* count_patterns, char* patterns,
                         GrepFlagsStruct* flags);

#endif  // SIMPLEBASHUTILS_SRC_GREP_HEADERS_PARSER_H_