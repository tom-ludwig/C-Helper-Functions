#include "dynamic_array.h"
#include <stdio.h>

int main() {
  DynamicArray *arr = dynamic_array_create(sizeof(int));

  // Adding elements to the array
  int value1 = 10, value2 = 20, value3 = 30;
  dynamic_array_append(arr, &value1);
  dynamic_array_append(arr, &value2);
  dynamic_array_append(arr, &value3);

  // Getting elements by index
  for (size_t i = 0; i < arr->size; ++i) {
    int *value = (int *)dynamic_array_get(arr, i);
    if (value) {
      printf("Element at index %zu: %d\n", i, *value);
    }
  }

  // Set an element at a specific index
  int new_value = 99;
  dynamic_array_set(arr, 1, &new_value); // Change value at index 1 to 99

  // Removing an element at index 0
  dynamic_array_remove(arr, 0);

  // Print array after removal
  printf("\nAfter removing index 0:\n");
  for (size_t i = 0; i < arr->size; ++i) {
    int *value = (int *)dynamic_array_get(arr, i);
    if (value) {
      printf("Element at index %zu: %d\n", i, *value);
    }
  }

  // Clear the array (without freeing memory)
  dynamic_array_clear(arr);

  printf("\nAfter clearing the array, size is: %zu\n", arr->size);

  dynamic_array_free(arr);
  return 0;
}
