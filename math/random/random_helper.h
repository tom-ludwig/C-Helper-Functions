/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#ifndef RANDOM_HELPERS_H
#define RANDOM_HELPERS_H

/**
 * @brief Generates a random integer between min and max (inclusive).
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random integer between min and max.
 */
int random_int(int min, int max);

/**
 * @brief Generates a random unsigned integer between min and max (inclusive).
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random unsigned integer between min and max.
 */
unsigned int random_uint(unsigned int min, unsigned int max);

/**
 * @brief Generates a random float between min and max (inclusive).
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random float between min and max.
 */
float random_float(float min, float max);

/**
 * @brief Generates a random long integer between min and max (inclusive).
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random long integer between min and max.
 */
long random_long(long min, long max);

/**
 * @brief Generates a random unsigned long integer between min and max
 * (inclusive).
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random unsigned long integer between min and max.
 */
unsigned long random_ulong(unsigned long min, unsigned long max);

/**
 * @brief Generates a random long long integer between min and max (inclusive).
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random long long integer between min and max.
 */
long long random_long_long(long long min, long long max);

/**
 * @brief Generates a random unsigned long long integer between min and max
 * (inclusive).
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random unsigned long long integer between min and max.
 */
unsigned long long random_ulong_long(unsigned long long min,
                                     unsigned long long max);

/**
 * @brief Generates a random double between min and max (inclusive).
 *
 * @param min The minimum value (inclusive).
 * @param max The maximum value (inclusive).
 * @return A random double between min and max.
 */
double random_double(double min, double max);

#endif
