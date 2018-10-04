/*Task. The goal of this problem is to represent a given positive integer n as a sum of as many pairwise
distinct positive integers as possible. That is, to fnd the maximum k such that n can be written as
a1 + a2 + · · · + ak where a1, . . . , ak are positive integers and ai ̸= aj for all 1 ≤ i < j ≤ k.
Input Format. The input consists of a single integer n.
Constraints. 1 ≤ n ≤ 109.
Output Format. In the frst line, output the maximum number k such that n can be represented as a sum
of k pairwise distinct positive integers. In the second line, output k pairwise distinct positive integers
that sum up to n (if there are many such representations, output any of them).*/

#include<stdio.h>
#include<stdlib.h>

void max_num_prizes(int, int*, int*);

void max_num_prizes(int n, int *k_count, int *k_array)
{
  int i = 1;
  while(n > 0)
  {

    if(n - i >= i + 1)
    {
      k_array = (int*)realloc(k_array, ++(*k_count) * sizeof(int));
      k_array[*k_count - 1] = i;
      n -= i++;
    }
    else break;
  }
  if(n > 0)
  {
    k_array = (int*)realloc(k_array, ++(*k_count) * sizeof(int));
    k_array[*k_count - 1] = n;
  }
  printf("%d\n", *k_count);
  for(int i = 0; i < *k_count; i++) printf("%d ", k_array[i]);
}

void main()
{
  int n = 0, k_count = 0;
  scanf("%d", &n);
  int *k_array = (int*)calloc(1, sizeof(int));
  max_num_prizes(n, &k_count, k_array);
  free(k_array);
}
