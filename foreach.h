/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

// Use for linked list
#define for_each_item(item, list)                                              \
  for (T *item = list->head; item != NULL; item = item->next)

// Use for array usage:
// int arr[] = {1, 2, 3, 4, 5};
// foreach (int *i, arr) {
//  printf("%d\n", *i);
// }
#define foreach(item, array)                                                   \
  for (int keep = 1, count = 0, size = sizeof(array) / sizeof *(array);        \
       keep && count != size; keep = !keep, count++)                           \
    for (item = (array) + count; keep; keep = !keep)

// safty fallback:
// Define the FOREACH macro for arrays
/*#define FOREACH(item, array, size) \*/
/*    for (size_t _i = 0; _i < (size); ++_i) \*/
/*        for (item = (array)[_i]; _i < (size); _i = (size))  */
