#include "safe_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

// Helper function to read a line from stdin safely
static bool read_line(char* buffer, size_t size) {
    if (!buffer || size == 0) return false;
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove newline
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Clear stdin buffer
        }
        return true;
    }
    return false;
}

// Function to safely parse an int
bool input_int(int* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        long temp = strtol(buffer, &endptr, 10);
        if (errno == 0 && *endptr == '\0' && temp >= INT_MIN && temp <= INT_MAX) {
            *value = (int)temp;
            return true;
        }
    }
    return false;
}

// Function to safely parse a long
bool input_long(long* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        long temp = strtol(buffer, &endptr, 10);
        if (errno == 0 && *endptr == '\0') {
            *value = temp;
            return true;
        }
    }
    return false;
}

// Function to safely parse a long long
bool input_long_long(long long* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        long long temp = strtoll(buffer, &endptr, 10);
        if (errno == 0 && *endptr == '\0') {
            *value = temp;
            return true;
        }
    }
    return false;
}

// Function to safely parse an unsigned int
bool input_unsigned_int(unsigned int* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        unsigned long temp = strtoul(buffer, &endptr, 10);
        if (errno == 0 && *endptr == '\0' && temp <= UINT_MAX) {
            *value = (unsigned int)temp;
            return true;
        }
    }
    return false;
}

// Function to safely parse an unsigned long
bool input_unsigned_long(unsigned long* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        unsigned long temp = strtoul(buffer, &endptr, 10);
        if (errno == 0 && *endptr == '\0') {
            *value = temp;
            return true;
        }
    }
    return false;
}

// Function to safely parse an unsigned long long
bool input_unsigned_long_long(unsigned long long* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        unsigned long long temp = strtoull(buffer, &endptr, 10);
        if (errno == 0 && *endptr == '\0') {
            *value = temp;
            return true;
        }
    }
    return false;
}

// Function to safely parse a float
bool input_float(float* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        float temp = strtof(buffer, &endptr);
        if (errno == 0 && *endptr == '\0') {
            *value = temp;
            return true;
        }
    }
    return false;
}

// Function to safely parse a double
bool input_double(double* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        double temp = strtod(buffer, &endptr);
        if (errno == 0 && *endptr == '\0') {
            *value = temp;
            return true;
        }
    }
    return false;
}

// Function to safely parse a long double
bool input_long_double(long double* value) {
    if (!value) return false;
    char buffer[64];
    if (read_line(buffer, sizeof(buffer))) {
        char* endptr;
        errno = 0;
        long double temp = strtold(buffer, &endptr);
        if (errno == 0 && *endptr == '\0') {
            *value = temp;
            return true;
        }
    }
    return false;
}

// Function to safely input a string
bool input_string(char* buffer, size_t size) {
    return read_line(buffer, size);
}
