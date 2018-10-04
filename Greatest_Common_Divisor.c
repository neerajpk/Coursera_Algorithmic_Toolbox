/*Task. Given two integers a and b, fnd their greatest common divisor.
Input Format. The two integers a, b are given in the same line separated by space.
Constraints. 1 ≤ a, b ≤ 2 * 10^9.
Output Format. Output GCD(a, b).

Using Euclidean algorithm.
*/

#include<stdio.h>

int gcd(int, int);

int gcd(int a, int b)
{
    if(b == 0) return a;
    gcd(b, a % b);
}

void main()
{
  int a = 0, b = 0;
  scanf("%d", &a);
  scanf("%d", &b);
  printf("%d", gcd(a, b));
}
