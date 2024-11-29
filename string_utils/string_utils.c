#include "string_utils.h"
#include <ctype.h>
#include <string.h>

char *trim(char *str) {
  char *end;

  // Trim leading space
  while (isspace((unsigned char)*str))
    str++;

  if (*str == 0)
    return str; // All spaces

  // Trim trailing space
  end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end))
    end--;

  // Null-terminate
  *(end + 1) = '\0';

  return str;
}

char *to_upper(char *str) {
  for (char *p = str; *p; ++p)
    *p = toupper((unsigned char)*p);
  return str;
}

char *to_lower(char *str) {
  for (char *p = str; *p; ++p)
    *p = tolower((unsigned char)*p);
  return str;
}
