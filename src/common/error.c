#include "error.h"

void ErrorNotArgumets() { fprintf(stderr, "Not argumets\n"); }
void ErrorInvalidOption() { fprintf(stderr, "Invalid option\n"); }
void ErrorMemmoryAllocate() { fprintf(stderr, "Error memmory allocate\n"); }
void ErrorNoFiles() { fprintf(stderr, "No files\n"); }
void ErrorNoSuchFile(char *name_file) {
  fprintf(stderr, "%s: No such file or directory\n", name_file);
}
