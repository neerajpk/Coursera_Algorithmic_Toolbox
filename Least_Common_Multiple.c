/*Task. Given two integers a and b, fnd their least common multiple.
Input Format. The two integers a and b are given in the same line separated by space.
Constraints. 1 ≤ a, b ≤ 2 * 10^9.
Output Format. Output the least common multiple of a and b*/

#include<stdio.h>
#include<inttypes.h>

int64_t gcd(int64_t, int64_t);

int64_t gcd(int64_t a, int64_t b)
{
    if(b == 0) return a;
    gcd(b, a % b);
}

void main()
{
  int64_t a = 0, b = 0;
  scanf("%"PRId64" %"PRId64, &a, &b);
  printf("%"PRId64, (a * b)/gcd(a, b));
}
