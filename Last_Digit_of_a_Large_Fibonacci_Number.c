/*Task. Given an integer n, fnd the last digit of the nth Fibonacci number Fn (that is, Fn mod 10).
Input Format. The input consists of a single integer n.
Constraints. 0 ≤ n ≤ 10^7.
Output Format. Output the last digit of Fn.*/

#include<stdio.h>
#include<stdlib.h>

int fibonacci(int, int*);

int fibonacci(int n, int *arr)
{
    arr[0]  = 0;
    arr[1]  = 1;
    for(int i = 2; i <= n; i++) arr[i] = (arr[i - 1] + arr[i - 2])%10;
    return arr[n];
}

void main()
{
  int n = 0;
  scanf("%d", &n);
  int *arr = (int*)malloc((n + 1) * sizeof(int));
  printf("%d", fibonacci(n, arr));
  free(arr);
}
