/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "random_helper.h"
#include <stdio.h>

int main() {
  printf("Random int: %d\n", random_int(1, 10));
  printf("Random unsigned int: %u\n", random_uint(1, 100));
  printf("Random float: %f\n", random_float(0.0, 1.0));
  printf("Random long: %ld\n", random_long(1L, 1000L));
  printf("Random unsigned long: %lu\n", random_ulong(1UL, 1000UL));
  printf("Random long long: %lld\n", random_long_long(1LL, 1000000LL));
  printf("Random unsigned long long: %llu\n",
         random_ulong_long(1ULL, 1000000ULL));
  printf("Random double: %f\n", random_double(0.0, 10.0));

  return 0;
}
