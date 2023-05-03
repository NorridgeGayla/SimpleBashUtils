#ifndef SIMPLEBASHUTILS_SRC_GREP_HEADERS_GREP_H_
#define SIMPLEBASHUTILS_SRC_GREP_HEADERS_GREP_H_

typedef struct GrepFlagsStruct {
  int flag_e;
  int flag_v;
  int flag_i;
  int flag_l;
  int flag_c;
  int flag_n;
  int flag_h;
  int flag_s;
  int flag_f;
  int flag_o;
} GrepFlagsStruct;

void my_grep(int argc, char** argv);

#endif  // SIMPLEBASHUTILS_SRC_GREP_HEADERS_GREP_H_
