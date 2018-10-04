/*Task. Given two integers n and m, output F(n) mod m (that is, the remainder of F(n) when divided by m).
Input Format. The input consists of two integers n and m given on the same line (separated by a space).
Constraints. 1 ≤ n ≤ 10^18, 2 ≤ m ≤ 1000.
Output Format. Output F(n) mod m.*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

int find_modulo(int64_t, int, int*);

int find_modulo(int64_t n, int m, int *arr)
{
  int count = 2;
  int i = 0;
  for(i = 2; i <= n; i++)
  {
    arr[i] = (arr[i - 1] + arr[i - 2]) % m;
    if(arr[i] == 1 && arr[i - 1] == 0)
    {
      count -= 1;
      break;
    }
    count++;
  }
  return (arr[n % count]);
}

void main()
{
  int64_t n = 0;
  int m = 0;
  scanf("%"PRId64" %d", &n, &m);
  int arr_size = (n < 1000) ? n + 1 : 1000;
  int *arr = (int*)calloc(arr_size, sizeof(int));
  arr[0] = 0;
  arr[1] = 1;
  printf("%d", find_modulo(n, m, arr));
  free(arr);
}
