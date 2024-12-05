#ifndef TIME_BLOCK_H
#define TIME_BLOCK_H

#include <stdio.h>
#include <string.h>
#include <time.h>

static clock_t start_time;
static clock_t end_time;
static double time_taken;

// Available units: ns, us, ms, s, m, h; Leave empty for dynamic scaling
#define TIME_BLOCK(label, unit, code_block)                                    \
  start_time = clock();                                                        \
  code_block;                                                                  \
  end_time = clock();                                                          \
  time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;             \
  if (unit && strcmp(unit, "ns") == 0) {                                       \
    printf("[%s] Time taken: %.3f nanoseconds\n", label, time_taken * 1e9);    \
  } else if (unit && strcmp(unit, "us") == 0) {                                \
    printf("[%s] Time taken: %.3f microseconds\n", label, time_taken * 1e6);   \
  } else if (unit && strcmp(unit, "ms") == 0) {                                \
    printf("[%s] Time taken: %.3f milliseconds\n", label, time_taken * 1e3);   \
  } else if (unit && strcmp(unit, "s") == 0) {                                 \
    printf("[%s] Time taken: %.3f seconds\n", label, time_taken);              \
  } else if (unit && strcmp(unit, "m") == 0) {                                 \
    printf("[%s] Time taken: %.3f minutes\n", label, time_taken / 60);         \
  } else if (unit && strcmp(unit, "h") == 0) {                                 \
    printf("[%s] Time taken: %.3f hours\n", label, time_taken / 3600);         \
  } else {                                                                     \
    /* Dynamic scaling if no valid unit is specified */                        \
    if (time_taken < 1e-6) {                                                   \
      printf("[%s] Time taken: %.3f nanoseconds\n", label, time_taken * 1e9);  \
    } else if (time_taken < 1e-3) {                                            \
      printf("[%s] Time taken: %.3f microseconds\n", label, time_taken * 1e6); \
    } else if (time_taken < 1) {                                               \
      printf("[%s] Time taken: %.3f milliseconds\n", label, time_taken * 1e3); \
    } else if (time_taken < 60) {                                              \
      printf("[%s] Time taken: %.3f seconds\n", label, time_taken);            \
    } else if (time_taken < 3600) {                                            \
      printf("[%s] Time taken: %.3f minutes\n", label, time_taken / 60);       \
    } else {                                                                   \
      printf("[%s] Time taken: %.3f hours\n", label, time_taken / 3600);       \
    }                                                                          \
  }

#endif // !TIME_BLOCK_H
