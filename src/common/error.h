#ifndef SIMPLEBASHUTILS_SRC_CAT_MY_ERROR_H_
#define SIMPLEBASHUTILS_SRC_CAT_MY_ERROR_H_

#include <stdio.h>

void ErrorNotArgumets();
void ErrorInvalidOption();
void ErrorMemmoryAllocate();
void ErrorNoFiles();
void ErrorNoSuchFile(char *name_file);

#endif  // SIMPLEBASHUTILS_SRC_CAT_MY_ERROR_H_
