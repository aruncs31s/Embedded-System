// Sum of 2 Numbers
#include <stdio.h>
int sum(int number_1, int number_2) { return number_1 + number_2; }
int main() {
  int a = 10;
  int b = 20;

  printf("a is %d\n", a);
  printf("b is %d\n", b);
  printf("Sum of a and b = %d \n", sum(a, b));
}
