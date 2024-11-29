#include "string_utils.h"
#include <stdio.h>

int main() {
  char text[] = "   Hello World!   ";
  printf("Trimmed: '%s'\n", trim(text));
  printf("Uppercase: '%s'\n", to_upper(text));
  printf("Lowercase: '%s'\n", to_lower(text));
  return 0;
}
