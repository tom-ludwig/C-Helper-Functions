/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "random_helper.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Internal function to initialize the random number generator once
static void ensure_random_initialized() {
  static bool initialized = false;
  if (!initialized) {
    srand((unsigned int)time(NULL));
    initialized = true;
  }
}

// Function to generate a random integer between min and max (inclusive)
int random_int(int min, int max) {
  ensure_random_initialized();
  return min + rand() % (max - min + 1);
}

// Function to generate a random unsigned integer between min and max
// (inclusive)
unsigned int random_uint(unsigned int min, unsigned int max) {
  ensure_random_initialized();
  return min + rand() % (max - min + 1);
}

// Function to generate a random float between min and max (inclusive)
float random_float(float min, float max) {
  ensure_random_initialized();
  return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

// Function to generate a random long integer between min and max (inclusive)
long random_long(long min, long max) {
  ensure_random_initialized();
  return min + rand() % (max - min + 1);
}

// Function to generate a random unsigned long integer between min and max
// (inclusive)
unsigned long random_ulong(unsigned long min, unsigned long max) {
  ensure_random_initialized();
  return min + rand() % (max - min + 1);
}

// Function to generate a random long long integer between min and max
// (inclusive)
long long random_long_long(long long min, long long max) {
  ensure_random_initialized();
  return min + (rand() % (max - min + 1));
}

// Function to generate a random unsigned long long integer between min and max
// (inclusive)
unsigned long long random_ulong_long(unsigned long long min,
                                     unsigned long long max) {
  ensure_random_initialized();
  return min + (rand() % (max - min + 1));
}

// Function to generate a random double between min and max (inclusive)
double random_double(double min, double max) {
  ensure_random_initialized();
  return min + ((double)rand() / (double)RAND_MAX) * (max - min);
}
