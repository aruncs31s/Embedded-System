#include <stdio.h>
int main(int argc, char *argv[]) {
  int num;
  char character;
  char string[5];
  float a_float;
  num = 10;
  character = 't';
  string[0] = 'H';
  string[1] = 'e';
  string[2] = 'l';
  string[3] = 'l';
  string[4] = 'o';
  a_float = 1.11111;

  printf("%d\n", num);
  printf("%c\n", character);
  printf("%s\n", string);
  printf("%f\n", a_float);
}
