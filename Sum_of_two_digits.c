#include<stdio.h>

int sum_of_two_digits(int, int);

int sum_of_two_digits(int a, int b)
{
  return a + b;
}

void main()
{
  int a = 0, b = 0;
  scanf("%d\n%d", &a, &b);
  printf("%d",sum_of_two_digits(a,b));
}
