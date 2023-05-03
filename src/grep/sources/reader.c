#include "../headers/reader.h"

char* OpenFile(int argc, char** argv, GrepFlagsStruct* flags, char* patterns,
               int* count_patterns) {
  int count_files = 0;
  int file_position = 0;
  if (flags->flag_e || flags->flag_f) {
    file_position = optind;
  } else {
    (*count_patterns)++;
    patterns = ToGetPatterns(*count_patterns, patterns, argv[optind]);
    file_position = optind + 1;
  }
  count_files = argc - file_position;
  if (patterns != NULL && count_files) {
    FILE* pFile = NULL;
    while (file_position < argc) {
      pFile = fopen(argv[file_position], "r");
      if (pFile != NULL) {
        Grep(flags, patterns, pFile, argv[file_position], count_files);
        fclose(pFile);
      } else {
        ErrorNoSuchFile(argv[file_position]);
      }
      file_position++;
    }
  } else {
    ErrorNotArgumets();
  }
  return patterns;
}

void Grep(GrepFlagsStruct* flags, char* patterns, FILE* pFile, char* name_file,
          int count_files) {
  int result = 0;
  regex_t regex;
  regmatch_t pmatch[1] = {0};
  size_t nmatch = 1;
  if (flags->flag_i) {
    result = regcomp(&regex, patterns, REG_ICASE | REG_EXTENDED);
  } else {
    result = regcomp(&regex, patterns, REG_EXTENDED);
  }
  if (!result) {
    char buf[BUFFER_SIZE] = {0};
    char prefix[BUFFER_SIZE] = {0};
    if (!flags->flag_h && count_files > 1) {
      strcpy(prefix, name_file);
      strcat(prefix, ":");
    }
    int match = 0;
    int count_match = 0;
    int line_number = 0;
    while (fgets(buf, BUFFER_SIZE, pFile) != NULL) {
      line_number++;
      match = regexec(&regex, buf, nmatch, pmatch, 0);
      if (flags->flag_v) {
        match = (match == 0) ? REG_NOMATCH : 0;
      }
      if (match != REG_NOMATCH) {
        count_match++;
        if (!flags->flag_l && !flags->flag_c) {
          if (flags->flag_n && !(flags->flag_v && flags->flag_o)) {
            printf("%s%d:", prefix, line_number);
          } else if (!(flags->flag_v && flags->flag_o)) {
            printf("%s", prefix);
          }
          if (flags->flag_o && !flags->flag_v) {
            Flag_o(match, buf, pmatch, nmatch, &regex, flags->flag_n, prefix,
                   line_number);
          } else if (!flags->flag_o) {
            printf("%s", buf);
            if (buf[strlen(buf) - 1] != '\n') {
              printf("\n");
            }
          }
        }
      }
    }
    if (flags->flag_l && count_match) {
      printf("%s\n", name_file);
    } else if (!flags->flag_l && flags->flag_c) {
      printf("%s%d\n", prefix, count_match);
    }
  } else {
    fprintf(stderr, "Regex error");
  }
  regfree(&regex);
}

void Flag_o(int match, char* buf, regmatch_t* pmatch, size_t nmatch,
            regex_t* regex, int flag_n, char* prefix, int line_number) {
  char* ptr = buf;
  int search = 1;
  int length = 0;
  int control = 0;
  while (!match && search) {
    if (control) {
      if (flag_n) {
        printf("%s%d:", prefix, line_number);
      } else {
        printf("%s", prefix);
      }
    }
    search = (pmatch[0].rm_eo == pmatch[0].rm_so) ? 0 : 1;
    if (search) {
      length = (int)(pmatch[0].rm_eo - pmatch[0].rm_so);
      printf("%.*s\n", length, ptr + pmatch[0].rm_so);
      ptr += pmatch[0].rm_eo;
      match = regexec(regex, ptr, nmatch, pmatch, REG_NOTBOL);
    }
    control = 1;
  }
}
