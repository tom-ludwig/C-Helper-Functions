/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

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
