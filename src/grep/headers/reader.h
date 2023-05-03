#ifndef SIMPLEBASHUTILS_SRC_GREP_HEADERS_READER_H_
#define SIMPLEBASHUTILS_SRC_GREP_HEADERS_READER_H_

#include <regex.h>

#include "../../common/error.h"
#include "my_grep.h"
#include "parser.h"

char* OpenFile(int argc, char** argv, GrepFlagsStruct* flags, char* patterns,
               int* count_patterns);
void Grep(GrepFlagsStruct* flags, char* patterns, FILE* pFile, char* name_file,
          int count_files);
void Flag_o(int match, char* buf, regmatch_t* pmatch, size_t nmatch,
            regex_t* regex, int flag_n, char* prefix, int line_number);

#endif  // SIMPLEBASHUTILS_SRC_GREP_HEADERS_READER_H_
