/*Task. Given an integer n, fnd the last digit of the sum F0 + F1 + · · · + Fn.
Input Format. The input consists of a single integer N.
Constraints. 0 ≤ N ≤ 10^18.
Output Format. Output the last digit of F0 + F1 + · · · + Fn.*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

int fibonacci(int64_t, int*);

int fibonacci(int64_t n, int *arr)
{
    if(n == 0 || n % 60 == 0) return 0;
    if(n == 1 || n % 60 == 1) return 1;
    arr[0]  = 0;
    arr[1]  = 1;
    int sum = 1;
    for(int i = 2; i <= n % 60; i++)
    {
      arr[i] = (arr[i - 1] + arr[i - 2])%10;
      sum = (sum + arr[i]) % 10;
    }
    return sum;
}

void main()
{
  int64_t n = 0;
  scanf("%"PRId64, &n);
  int *arr = (int*)malloc(65 * sizeof(int));
  printf("%d", fibonacci(n, arr));
  free(arr);
}
