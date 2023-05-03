#ifndef SIMPLEBASHUTILS_SRC_CAT_HEADERS_READER_H_
#define SIMPLEBASHUTILS_SRC_CAT_HEADERS_READER_H_

#include "../../common/error.h"
#include "my_cat.h"
#include "parser.h"

void RunSomeCatFunc(int argc, char **argv, CatFlagsStruct *flags);
void SelectCatFunction(CatFlagsStruct *flags, FILE *pFile);
void SimpleCatFunc(FILE *pFile);
void Flag_b_func(FILE *pFile);
void Flag_E_func(FILE *pFile);
void Flag_n_func(FILE *pFile);
void Flag_s_func(FILE *pFile);
void Flag_T_func(FILE *pFile);
void Flags_etv_func(FILE *pFile, char invisible_char);

#endif  // SIMPLEBASHUTILS_SRC_CAT_HEADERS_READER_H_
