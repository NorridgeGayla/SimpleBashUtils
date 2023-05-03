#ifndef SIMPLEBASHUTILS_SRC_CAT_PARSER_H_
#define SIMPLEBASHUTILS_SRC_CAT_PARSER_H_

#include <getopt.h>
#include <string.h>

#include "../../common/error.h"
#include "my_cat.h"

#define CHECK_FLAGS "benstvTE"

int ParserFlags(int argc, char **argv, CatFlagsStruct *flags);
char **ParserFiles(int argc, char **argv, int *amount_files);

#endif  // SIMPLEBASHUTILS_SRC_CAT_PARSER_H_
