/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "dynamic_array.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Create a new dynamic array with a given element size
DynamicArray* dynamic_array_create(size_t element_size) {
    DynamicArray* array = malloc(sizeof(DynamicArray));
    if (!array) return NULL;

    array->element_size = element_size;
    array->size = 0;
    array->capacity = 4; // Start with a small capacity
    array->data = malloc(element_size * array->capacity);
    if (!array->data) {
        free(array);
        return NULL;
    }

    return array;
}

// Free the memory allocated for the dynamic array
void dynamic_array_free(DynamicArray* array) {
    if (array) {
        free(array->data);
        free(array);
    }
}

// Append an element to the dynamic array, resizing if necessary
bool dynamic_array_append(DynamicArray* array, const void* element) {
    if (array->size >= array->capacity) {
        size_t new_capacity = array->capacity * 2;
        if (!dynamic_array_resize(array, new_capacity)) {
            return false;
        }
    }

    memcpy((char*)array->data + array->size * array->element_size, element, array->element_size);
    array->size++;
    return true;
}

// Resize the dynamic array to a new capacity
bool dynamic_array_resize(DynamicArray* array, size_t new_capacity) {
    if (new_capacity <= array->capacity) return false;

    void* new_data = realloc(array->data, new_capacity * array->element_size);
    if (!new_data) return false; // Allocation failed
    array->data = new_data;
    array->capacity = new_capacity;
    return true;
}

// Get an element at a specified index
void* dynamic_array_get(DynamicArray* array, size_t index) {
    if (index >= array->size) {
        return NULL; // Out of bounds
    }
    return (char*)array->data + index * array->element_size;
}

// Set an element at a specified index
bool dynamic_array_set(DynamicArray* array, size_t index, const void* element) {
    if (index >= array->size) {
        return false; // Out of bounds
    }
    memcpy((char*)array->data + index * array->element_size, element, array->element_size);
    return true;
}

// Remove an element at a specified index
bool dynamic_array_remove(DynamicArray* array, size_t index) {
    if (index >= array->size) {
        return false; // Out of bounds
    }

    // Shift all elements after the removed one down by one position
    for (size_t i = index; i < array->size - 1; ++i) {
        memcpy((char*)array->data + i * array->element_size,
               (char*)array->data + (i + 1) * array->element_size,
               array->element_size);
    }

    array->size--;
    return true;
}

// Clear all elements in the array, resetting size but not capacity
void dynamic_array_clear(DynamicArray* array) {
    array->size = 0;
}

// Copy the content from one dynamic array to another
void dynamic_array_copy(DynamicArray* dest, const DynamicArray* src) {
    if (dest->element_size != src->element_size) {
        return; // Element sizes must be the same
    }
    dynamic_array_resize(dest, src->capacity);
    memcpy(dest->data, src->data, src->size * src->element_size);
    dest->size = src->size;
}

// Check if the array is full (size == capacity)
bool dynamic_array_is_full(DynamicArray* array) {
    return array->size == array->capacity;
}
