#include "../headers/reader.h"

void RunSomeCatFunc(int argc, char **argv, CatFlagsStruct *flags) {
  FILE *pFile = NULL;
  while (optind < argc) {
    if ((pFile = fopen(argv[optind], "r")) != NULL) {
      SelectCatFunction(flags, pFile);
      fclose(pFile);
    } else {
      ErrorNoSuchFile(argv[optind]);
    }
    optind++;
  }
}

void SelectCatFunction(CatFlagsStruct *flags, FILE *pFile) {
  char invisible_char = '\0';
  if (flags->flag_b) {
    Flag_b_func(pFile);
  } else if (flags->flag_e) {
    invisible_char = '\n';
    Flags_etv_func(pFile, invisible_char);
  } else if (flags->flag_E) {
    Flag_E_func(pFile);
  } else if (flags->flag_s) {
    Flag_s_func(pFile);
  } else if (flags->flag_t) {
    invisible_char = '\t';
    Flags_etv_func(pFile, invisible_char);
  } else if (flags->flag_T) {
    Flag_T_func(pFile);
  } else if (flags->flag_n) {
    Flag_n_func(pFile);
  } else if (flags->flag_v) {
    Flags_etv_func(pFile, invisible_char);
  } else {
    SimpleCatFunc(pFile);
  }
}

void SimpleCatFunc(FILE *pFile) {
  char symbol;
  while ((symbol = fgetc(pFile)) != EOF) {
    printf("%c", symbol);
  }
}

void Flag_b_func(FILE *pFile) {
  char current_symbol;
  char previous_symbol = '\n';
  int number_line = 1;
  while ((current_symbol = fgetc(pFile)) != EOF) {
    if (previous_symbol == '\n' && current_symbol != '\n') {
      printf("%6d\t", number_line++);
    }
    printf("%c", current_symbol);
    previous_symbol = current_symbol;
  }
}

void Flags_etv_func(FILE *pFile, char invisible_char) {
  int current_symbol;
  while ((current_symbol = fgetc(pFile)) != EOF) {
    if ((current_symbol >= 0 && current_symbol < 9) ||
        (current_symbol > 10 && current_symbol < 32)) {
      printf("^%c", current_symbol + 64);
    } else if (current_symbol == 127) {
      printf("^?");
    } else if (current_symbol > 127 && current_symbol < 160) {
      printf("M-^%c", current_symbol - 64);
    } else if (current_symbol > 160 && current_symbol < 255) {
      printf("M-%c", current_symbol - 128);
    } else if (current_symbol == 255) {
      printf("M-^?");
    } else if (current_symbol != invisible_char || invisible_char == '\0') {
      printf("%c", current_symbol);
    } else if (current_symbol == invisible_char && invisible_char == '\n') {
      printf("$\n");
    } else if (current_symbol == invisible_char && invisible_char == '\t') {
      printf("^I");
    }
  }
}

void Flag_E_func(FILE *pFile) {
  char current_symbol;
  while ((current_symbol = fgetc(pFile)) != EOF) {
    if (current_symbol == '\n') {
      printf("$\n");
    } else {
      printf("%c", current_symbol);
    }
  }
}

void Flag_n_func(FILE *pFile) {
  char current_symbol;
  char previous_symbol = '\n';
  int number_line = 1;
  while ((current_symbol = fgetc(pFile)) != EOF) {
    if (previous_symbol == '\n') {
      printf("%6d\t", number_line++);
    }
    printf("%c", current_symbol);
    previous_symbol = current_symbol;
  }
}

void Flag_s_func(FILE *pFile) {
  char current_symbol;
  char previous_symbol = '\0';
  while ((current_symbol = fgetc(pFile)) != EOF) {
    printf("%c", current_symbol);
    if (previous_symbol == '\n' && current_symbol == '\n') {
      while (current_symbol == '\n') {
        current_symbol = fgetc(pFile);
      }
      printf("%c", current_symbol);
    }
    previous_symbol = current_symbol;
  }
}

void Flag_T_func(FILE *pFile) {
  char current_symbol;
  while ((current_symbol = fgetc(pFile)) != EOF) {
    if (current_symbol == '\t') {
      printf("^I");
    } else {
      printf("%c", current_symbol);
    }
  }
}
