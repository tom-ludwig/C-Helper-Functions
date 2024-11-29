#include "safe_input.h"
#include <stdio.h>

int main() {
  int int_val;
  double double_val;
  char str[100];

  printf("Enter an integer: ");
  if (input_int(&int_val)) {
    printf("You entered: %d\n", int_val);
  } else {
    printf("Invalid input for integer.\n");
  }

  printf("Enter a double: ");
  if (input_double(&double_val)) {
    printf("You entered: %.2f\n", double_val);
  } else {
    printf("Invalid input for double.\n");
  }

  printf("Enter a string: ");
  if (input_string(str, sizeof(str))) {
    printf("You entered: %s\n", str);
  } else {
    printf("Invalid input for string.\n");
  }

  return 0;
}
