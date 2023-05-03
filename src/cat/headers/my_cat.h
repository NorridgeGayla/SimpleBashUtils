#ifndef SIMPLEBASHUTILS_SRC_CAT_MY_CAT_H_
#define SIMPLEBASHUTILS_SRC_CAT_MY_CAT_H_

typedef struct CatFlagsStruct {
  int flag_b;
  int flag_e;
  int flag_E;
  int flag_n;
  int flag_s;
  int flag_t;
  int flag_T;
  int flag_v;
} CatFlagsStruct;

void my_cat(int argc, char** argv);

#endif  // SIMPLEBASHUTILS_SRC_CAT_MY_CAT_H_
