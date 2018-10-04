/*As we already know, a natural greedy strategy for the change problem does not work correctly for any set of
denominations. For example, if the available denominations are 1, 3, and 4, the greedy algorithm will change
6 cents using three coins (4 + 1 + 1) while it can be changed using just two coins (3 + 3). Your goal now is
to apply dynamic programming for solving the Money Change Problem for denominations 1, 3, and 4.
Problem Description
Input Format. Integer money.
Output Format. The minimum number of coins with denominations 1, 3, 4 that changes money.
Constraints. 1 ≤ money ≤ 10^3*/

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int money_change_again(int, int*);
int min(int, int, int);

int min(int a, int b, int c)
{
  int min_val = INT_MAX;
  if(a < min_val) min_val = a;
  if(b < min_val) min_val = b;
  if(c < min_val) min_val = c;
  return min_val;
}

int money_change_again(int n, int* array)
{
  if(n < 0) return INT_MAX - 1;
  if(n == 0) return 0;
  if(array[n - 1] != 0) return array[n - 1];
  array[n - 1] = min(money_change_again(n - 1, array) + 1, money_change_again(n - 3, array) + 1, money_change_again(n - 4, array) + 1);
  return array[n - 1];
}

void main()
{
  int n;
  scanf("%d", &n);
  int* array = (int*)calloc(n, sizeof(int));
  printf("%d", money_change_again(n, array));
  free(array);
}
