/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// File operations
bool file_exists(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

bool file_read(const char* filename, void* buffer, size_t size) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return false;  // File could not be opened
    }

    size_t read_size = fread(buffer, 1, size, file);
    fclose(file);

    return read_size == size;  // Return true if the entire size was read
}

bool file_write(const char* filename, const void* data, size_t size) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        return false;  // File could not be opened
    }

    size_t written_size = fwrite(data, 1, size, file);
    fclose(file);

    return written_size == size;  // Return true if the entire size was written
}

bool file_append(const char* filename, const void* data, size_t size) {
    FILE* file = fopen(filename, "ab");
    if (!file) {
        return false;  // File could not be opened
    }

    size_t written_size = fwrite(data, 1, size, file);
    fclose(file);

    return written_size == size;  // Return true if the entire size was written
}

bool file_delete(const char* filename) {
    return remove(filename) == 0;  // Return true if deletion was successful
}

bool file_clear(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        return false;  // File could not be opened
    }

    fclose(file);  // Simply close the file, it clears the content
    return true;
}

// Directory operations
bool directory_exists(const char* dirname) {
    struct stat st;
    return stat(dirname, &st) == 0 && S_ISDIR(st.st_mode); // Check if it exists and is a directory
}

bool directory_create(const char* dirname) {
    return mkdir(dirname, 0755) == 0; // Create directory with rwx permissions for owner and rx for group/others
}

bool directory_remove(const char* dirname) {
    return rmdir(dirname) == 0; // Remove the directory
}

// List files in the directory and return full paths
DirectoryList directory_list(const char* dirname) {
    DirectoryList result = {NULL, 0};

    DIR* dir = opendir(dirname);
    if (!dir) {
        return result;  // Directory could not be opened, return empty result
    }

    struct dirent* entry;
    size_t count = 0;
    
    // First pass: Count files
    while ((entry = readdir(dir)) != NULL) {
        // Skip '.' and '..' entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            count++;
        }
    }

    // Allocate memory for the result
    result.paths = (char**)malloc(count * sizeof(char*));
    if (!result.paths) {
        closedir(dir);
        return result;  // Memory allocation failed, return empty result
    }

    // Second pass: Store full paths
    rewinddir(dir);
    size_t idx = 0;
    while ((entry = readdir(dir)) != NULL) {
        // Skip '.' and '..' entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Allocate memory for the full path and copy it
            size_t path_len = strlen(dirname) + strlen(entry->d_name) + 2;  // 1 for '/' and 1 for '\0'
            result.paths[idx] = (char*)malloc(path_len);
            if (result.paths[idx]) {
                snprintf(result.paths[idx], path_len, "%s/%s", dirname, entry->d_name);
            }
            idx++;
        }
    }

    result.count = count;
    closedir(dir);
    return result;
}

// Free the memory allocated for directory listing
void free_directory_list(DirectoryList* dir_list) {
    if (dir_list && dir_list->paths) {
        for (size_t i = 0; i < dir_list->count; i++) {
            free(dir_list->paths[i]);
        }
        free(dir_list->paths);
        dir_list->paths = NULL;
        dir_list->count = 0;
    }
}
