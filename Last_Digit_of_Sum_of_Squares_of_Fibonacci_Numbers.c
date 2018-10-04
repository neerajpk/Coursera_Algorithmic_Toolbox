/*Task. Compute the last digit of F0^2 + F1^2 + · · · + Fn^2.
Input Format. Integer n.
Constraints. 0 ≤ n ≤ 1018.
Output Format. The last digit of F0^2 + F1^2 + · · · + Fn^2.*/

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
      sum = (sum + (arr[i] * arr[i])) % 10;
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
