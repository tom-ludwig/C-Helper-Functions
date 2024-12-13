/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stddef.h>
#include <stdbool.h>
//
// Struct to hold the result of directory listing
typedef struct {
    char** paths;  // Array of full file paths
    size_t count;  // Number of files
} DirectoryList;

// File operations
bool file_exists(const char* filename);
bool file_read(const char* filename, void* buffer, size_t size);
bool file_write(const char* filename, const void* data, size_t size);
bool file_append(const char* filename, const void* data, size_t size);
bool file_delete(const char* filename);
bool file_clear(const char* filename);

// Directory operations
bool directory_exists(const char* dirname);
bool directory_create(const char* dirname);
bool directory_remove(const char* dirname);
DirectoryList directory_list(const char* dirname);
void free_directory_list(DirectoryList* dir_list);

#endif // FILE_UTILS_H
