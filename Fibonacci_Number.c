/*Task. Given an integer n, fnd the nth Fibonacci number F(n).
Input Format. The input consists of a single integer n.
Constraints. 0 ≤ n ≤ 45.
Output Format. Output F(n)*/

#include<stdio.h>
#include<stdlib.h>

int fibonacci(int, int*);

int fibonacci(int n, int *arr)
{
    if(n == 0 || n == 1) return arr[n];
    if(n > 1 && arr[n] == 0) arr[n] = fibonacci(n - 1, arr) + fibonacci(n - 2, arr);
    return arr[n];
}

void main()
{
  int n = 0;
  scanf("%d", &n);
  int *arr = (int*)calloc((n + 1), sizeof(int));
  arr[0] = 0;
  arr[1] = 1;
  printf("%d", fibonacci(n, arr));
  free(arr);
}
