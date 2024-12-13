/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

// Define the DynamicArray structure
typedef struct {
    void* data;             // Pointer to the array's data
    size_t element_size;    // Size of each element in the array
    size_t size;            // Current number of elements in the array
    size_t capacity;        // Total capacity of the array (allocated size)
} DynamicArray;

// Function prototypes
DynamicArray* dynamic_array_create(size_t element_size);
void dynamic_array_free(DynamicArray* array);
bool dynamic_array_append(DynamicArray* array, const void* element);
void* dynamic_array_get(DynamicArray* array, size_t index);
bool dynamic_array_set(DynamicArray* array, size_t index, const void* element);
bool dynamic_array_remove(DynamicArray* array, size_t index);
bool dynamic_array_resize(DynamicArray* array, size_t new_capacity);
void dynamic_array_clear(DynamicArray* array);
void dynamic_array_copy(DynamicArray* dest, const DynamicArray* src);
bool dynamic_array_is_full(DynamicArray* array);

#endif // DYNAMIC_ARRAY_H
