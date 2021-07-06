#include <stdio.h>

int main() {

  float a,b,c,d,e,f;
  float subX, subY, x, y, defX, defY;

  // Getting Input 2x3 normal form
  printf("Input a for expression 1: ");
  scanf("%f", &a);
  printf("Input b for expression 1: ");
  scanf("%f", &b);
  printf("Input c for expression 1: ");
  scanf("%f", &c);
  printf("Input d for expression 2: ");
  scanf("%f", &d);
  printf("Input e for expression 2: ");
  scanf("%f", &e);
  printf("Input f for expression 2: ");
  scanf("%f", &f);

  defX = 0;
  defY = 0;

  x = (c - (b * defY)) / a;
  y = (f - (d * defX)) / e;

  printf("x_1: %.2f, y_1: %.2f", x, y);

  return 0;
}
