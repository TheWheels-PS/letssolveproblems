#include <iostream>

long long data[91];

long long Fibonacci(const int num) {
  if (num == 0) {
    return 0;
  } else if (num == 1) {
    return 1;
  } else if (data[num])
    return data[num];

  return data[num] = Fibonacci(num - 2) + Fibonacci(num - 1);
}

int main() {
  int num;
  long long result;

  scanf("%d", &num);

  result = Fibonacci(num);
  printf("%lld", result);
  return 0;
}
