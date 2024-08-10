#include <stdio.h>
int main() {
  int i_number;
  float f_number;
  char character;
  char string[10];
  printf("Enter the integer\n");
  scanf("%d", &i_number);
  printf("Enter the float\n");
  scanf("%f", &f_number);
  printf("Enter the character\n");
  scanf("%c", &character);
  printf("Enter the string\n");
  scanf("%9s", string);
}
