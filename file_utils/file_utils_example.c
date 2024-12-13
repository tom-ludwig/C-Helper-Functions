/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "file_utils.h"
#include <stdio.h>
#include <string.h>

int main() {
  const char *filename = "example.txt";
  const char *data_to_write = "Hello, File and Directory Utils!";
  const char *dir_name = "example_dir";

  // File operations
  if (file_write(filename, data_to_write, strlen(data_to_write) + 1)) {
    printf("Data written to file successfully.\n");
  } else {
    printf("Failed to write data to file.\n");
  }

  if (file_exists(filename)) {
    printf("File exists.\n");

    // Read the data from the file
    char buffer[50];
    if (file_read(filename, buffer, sizeof(buffer))) {
      printf("Data read from file: %s\n", buffer);
    } else {
      printf("Failed to read data from file.\n");
    }
  }

  // Directory operations
  if (!directory_exists(dir_name)) {
    printf("Directory does not exist, creating...\n");
    if (directory_create(dir_name)) {
      printf("Directory created successfully.\n");
    } else {
      printf("Failed to create directory.\n");
    }
  }

  // Listing files in the directory
  if (directory_exists(dir_name)) {
    printf("Listing files in the directory:\n");
    directory_list(dir_name);
  }

  // Remove the directory (must be empty)
  if (directory_remove(dir_name)) {
    printf("Directory removed successfully.\n");
  } else {
    printf("Failed to remove directory.\n");
  }

  // Clean up file after operations
  if (file_delete(filename)) {
    printf("File deleted successfully.\n");
  } else {
    printf("Failed to delete file.\n");
  }

  const char *dirname = "example_dir";

  // List files in the directory
  DirectoryList dir_list = directory_list(dirname);

  if (dir_list.count > 0) {
    printf("Files in directory '%s':\n", dirname);
    for (size_t i = 0; i < dir_list.count; i++) {
      printf("%s\n", dir_list.paths[i]);
    }

    // Free the allocated memory for the directory list
    free_directory_list(&dir_list);
  } else {
    printf("No files found or directory could not be opened.\n");
  }

  return 0;
}
