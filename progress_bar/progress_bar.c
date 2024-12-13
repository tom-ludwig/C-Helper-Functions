/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "progress_bar.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void progress_bar(double percentage, bool withColor) {
  int val = (int)(percentage * 100);
  int lpad = (int)(percentage * PBWIDTH);
  int rpad = PBWIDTH - lpad;

  int red = 255, green = 0, blue = 0;
  int red_end = 166, green_end = 227, blue_end = 161;

  // Gradients to smoothen the transition from red to yellow to green
  if (percentage <= 0.5) {
    red = 255;
    green = (int)(255 * percentage * 2);
    blue = 0;
  } else {
    red = (int)(166 - (percentage - 0.5) * 2 * 166);
    green = 227;
    blue = 161;
  }

  // Format the color using ANSI escape codes (RGB for text color)
  char color[50];
  snprintf(color, sizeof(color), "\033[38;2;%d;%d;%dm", red, green, blue);

  if (val == 100) {
    printf("\r %s \xE2\x9C\x94  %3d%% [%.*s%*s]\n", color, val, lpad, PBSTR,
           rpad, "");
  } else {
    if (withColor) {
      printf("\r %s %3d%% [%.*s%*s]", color, val, lpad, PBSTR, rpad, "");
    } else {
      printf("\r %3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    }
  }

  printf("\033[0m"); // Reset color (for any further output)
  fflush(stdout);    // Ensure the output is printed immediately
}
