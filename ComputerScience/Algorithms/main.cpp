/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

// fibonacci sequence function recursive
int fib(int n)
{
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

// fibonacci sequence function dynamic programming
int fibDP(int n)
{
  int* f = new int[n + 2];
  int i;

  f[0] = 0;
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
    f[i] = f[i - 1] + f[i - 2];
  }

  return f[n];
}

int main()
{

  // std::cout << "fib(100): " << fib(100) << std::endl; // super slow
  std::cout << "fibDP(100): " << fibDP(100) << std::endl; // super fast
  return 0;
}