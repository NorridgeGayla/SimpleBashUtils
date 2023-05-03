#ifndef SRC_GREP_GREP_H
#define SRC_GREP_GREP_H

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

void S21Grep(int argc, char** argv);

#endif  // SRC_GREP_GREP_H
