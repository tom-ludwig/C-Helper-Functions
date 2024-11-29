#include <stdio.h>

#define printfln(format, ...) printf(format "\n", ##__VA_ARGS__)
