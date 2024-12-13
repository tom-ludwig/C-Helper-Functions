/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#ifndef SAFE_INPUT_H
#define SAFE_INPUT_H

#include <stdbool.h>
#include <stddef.h>

// Function declarations for safe input methods
bool input_int(int *value);
bool input_long(long *value);
bool input_long_long(long long *value);
bool input_unsigned_int(unsigned int *value);
bool input_unsigned_long(unsigned long *value);
bool input_unsigned_long_long(unsigned long long *value);
bool input_float(float *value);
bool input_double(double *value);
bool input_long_double(long double *value);
bool input_string(char *buffer, size_t size);

#endif // SAFE_INPUT_H
