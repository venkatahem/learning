#include <stdio.h>

long long int dtob(long long int x) {
  long long int sum = 0, y, z = 1;
  while (x != 0) {
    y = x % 2;
    sum = (sum + y) * z;
    z = z * 10;
    x = x / 2;
  }
  return sum;
}
int main() {
  long long int a;
  long long int z, b, sum = 0;
  printf("\nEnter a number: ");
  scanf_s("%lld", &a);
  z = dtob(a);
  printf("\n%lld\n", z);

  return 0;
}