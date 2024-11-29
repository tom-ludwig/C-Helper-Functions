#include "progress_bar.h"
#include <stdio.h>

long long fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

long long dynamicFibonacci(int n) {
  if (n <= 1)
    return n; // Base cases: F(0) = 0, F(1) = 1

  long long fib[n + 1]; // Array to store Fibonacci numbers
  fib[0] = 0;
  fib[1] = 1;

  for (int i = 2; i <= n; i++) {
    progress_bar((double)i / n, false);
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  return fib[n]; // Return the nth Fibonacci number
}

void print_progress_loop() {
  for (int i = 0; i < 100; i++) {
    fibonacci(35);
  }

  printf("\n");
}
int main() {
  printf("Calcualting the 1000000th Fibonacci number \n");
  printf("\n Fibunacci: %lld", dynamicFibonacci(1000000));
  return 0;
}
