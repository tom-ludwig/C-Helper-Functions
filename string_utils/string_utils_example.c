/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "string_utils.h"
#include <stdio.h>

int main() {
  char text[] = "   Hello World!   ";
  printf("Trimmed: '%s'\n", trim(text));
  printf("Uppercase: '%s'\n", to_upper(text));
  printf("Lowercase: '%s'\n", to_lower(text));
  return 0;
}
