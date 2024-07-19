#include <stdio.h>
int main() {
  int n1 = 0, n2 = 1, n3, i, size;
  printf("Enter the number of elements:");
  scanf("%d", &size);
  printf("\n%d %d", n1, n2);
  for (i = 2; i < size; i++) {
    n3 = n1 + n2;
    printf(" %d", n3);
    n1 = n2;
    n2 = n3;
  }
  return 0;
}