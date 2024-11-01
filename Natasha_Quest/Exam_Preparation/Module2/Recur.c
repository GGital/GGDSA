// Recursive function

#include <stdio.h>

long long int factorial(int num)
{
  if (num == 0 || num == 1)
    return 1;
  else
    return factorial(num - 1) * num;
}

int main()
{
  int n = 15;
  printf("%lld \n", factorial(n));

  return 0;
}
