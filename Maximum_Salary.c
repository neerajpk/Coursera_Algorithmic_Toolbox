/*Task. Compose the largest number out of a set of integers.
Input Format. The frst line of the input contains an integer n. The second line contains integers
a1, a2, . . . , an.
Constraints. 1 ≤ n ≤ 100; 1 ≤ ai ≤ 103 for all 1 ≤ i ≤ n.
Output Format. Output the largest number that can be composed out of a1, a2, . . . , an.*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int*, int*);
int count(int);
bool isgreater(int, int);
void maximum_salary(int*, int);

void swap(int* p, int* q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

int count(int num)
{
  int count = 0;
  while(num > 0)
  {
    num = num/10;
    count++;
  }
  return count;
}

bool isgreater(int num, int max)
{
  int num_count = count(num), max_count = count(max), temp1 = num, temp2 = max, i = 0;
  for(i = 0; i < max_count; i++) temp1 *= 10;
  temp1 += max;
  for(i = 0; i < num_count; i++) temp2 *= 10;
  temp2 += num;
  return (temp1 > temp2 ? true : false);
}

void maximum_salary(int* input_array, int n)
{
  int max_index = 0, i = 0, j = 0;
  while(i < n)
  {
    max_index = i;
    j = i + 1;
    while(j < n)
    {
      if(input_array[j] != input_array[max_index] && isgreater(input_array[j], input_array[max_index])) max_index = j;
      j++;
    }
    swap(&input_array[i++], &input_array[max_index]);
  }
}

void main()
{
  int n = 0;
  scanf("%d", &n);
  int *input_array = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) scanf("%d", &input_array[i]);
  maximum_salary(input_array, n);
  for(int i = 0; i < n; i++) printf("%d", input_array[i]);
  free(input_array);
}
