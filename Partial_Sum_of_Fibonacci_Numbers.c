/*Task. Given two non-negative integers m and n, where m ≤ n, fnd the last digit of the sum Fm + Fm+1 +
· · · + Fn.
Input Format. The input consists of two non-negative integers m and n separated by a space.
Constraints. 0 ≤ m ≤ n ≤ 10^18.
Output Format. Output the last digit of Fm + Fm+1 + · · · + Fn*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

int fibonacci_partial_sum(int64_t, int64_t, int*);

int fibonacci_partial_sum(int64_t m, int64_t n, int *arr)
{
    int sum_m = 0, sum_n = 0, i = 2, j = 2;
    arr[0]  = 0;
    arr[1]  = 1;
    if(m > 1) sum_m += 1;
    if(n >= 1) sum_n += 1;
    for(; i <= n % 60; i++)
    {
      arr[i] = (arr[i - 1] + arr[i - 2])%10;
      sum_n = (sum_n + arr[i]) % 10;
      if(j < m % 60)
      {
        sum_m = (sum_m + arr[i]) % 10;
        j++;
      }
    }
    return (sum_n >= sum_m) ? sum_n - sum_m : (sum_n - sum_m) + 10;
}

void main()
{
  int64_t m = 0, n = 0;
  scanf("%"PRId64" %"PRId64, &m, &n);
  int *arr = (int*)malloc(65 * sizeof(int));
  printf("%d", fibonacci_partial_sum(m, n, arr));
  free(arr);
}
