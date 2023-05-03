#ifndef SRC_GREP_READER_H
#define SRC_GREP_READER_H

#include <regex.h>

#include "../common/error.h"
#include "parser.h"
#include "s21_grep.h"

char* OpenFile(int argc, char** argv, GrepFlagsStruct* flags, char* patterns,
               int* count_patterns);
void Grep(GrepFlagsStruct* flags, char* patterns, FILE* pFile, char* name_file,
          int count_files);
void Flag_o(int match, char* buf, regmatch_t* pmatch, size_t nmatch,
            regex_t* regex, int flag_n, char* prefix, int line_number);

#endif  // RSRC_GREP_READER_H
