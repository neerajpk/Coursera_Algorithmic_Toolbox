/*Task. The goal in this problem is to fnd the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10.
Input Format. The input consists of a single integer m.
Constraints. 1 ≤ m ≤ 103.
Output Format. Output the minimum number of coins with denominations 1, 5, 10 that changes m.*/

#include<stdio.h>

int money_change(int);

int money_change(int n)
{
  int denom_count = 0, i = 0;
  int denom[3] = {10,5,1};
  while(n > 0)
  {
      denom_count += n / denom[i];
      n -= ((n/denom[i]) * denom[i++]);
  }
  return denom_count;
}

void main()
{
  int n = 0;
  scanf("%d",&n);
  printf("%d", money_change(n));
}
