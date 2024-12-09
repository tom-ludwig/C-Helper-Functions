#include "time_block.h"

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
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  return fib[n]; // Return the nth Fibonacci number
}

int main() {
  // Find out how long it takes to calculate the 10th Fibonacci number
  TIME_BLOCK("Classic Fibonacci sequens of 40", "", fibonacci(40));
  TIME_BLOCK("Classic Fibonacci sequens of 40", "", fibonacci(40));

  TIME_BLOCK("Classic Fibonacci sequens of 41", "", fibonacci(41));

  TIME_BLOCK("Dynamic Fibonacci sequence for 40", "ns", dynamicFibonacci(40));

  TIME_BLOCK("Dynamic Fibonacci sequence for 1000", "ns",
             dynamicFibonacci(1000));

  // NOTE: If necessary to use variables outside the TIME_BLOCK afterwards
  // define them outside first
  int i = 20;
  TIME_BLOCK("Use varibles outside the TIME_BLOCK", "", fibonacci(i); ++i;);
  printf("%d\n", i);

  return 0;
}
