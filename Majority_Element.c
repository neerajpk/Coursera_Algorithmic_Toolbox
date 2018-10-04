#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool check(int*, int, int, int);
int majority_element(int*, int, int);

bool check(int* input_array, int low, int high, int val)
{
  int count = 0, size = high - low + 1, i = 0;
  for(i = low; i <= high; i++)
  {
    if(input_array[i] == val) count++;
    if(count > size/2) return true;
  }
  return false;
}

int majority_element(int* input_array, int low, int high)
{
  if(low == high) return input_array[low];
  int mid = (low + high)/2;
  int left_maj = majority_element(input_array, low, mid);
  int right_maj = majority_element(input_array, mid + 1, high);
  if(left_maj != -1 || right_maj != -1)
  {
    if(right_maj != -1 && check(input_array, low, high, right_maj)) return right_maj;
    else if(left_maj != -1 && check(input_array, low, high, left_maj)) return left_maj;
    else return -1;
  }
  else return -1;
}

void main()
{
  int n, ret_val;
  scanf("%d", &n);
  int* input_array = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) scanf("%d", &input_array[i]);
  ret_val = majority_element(input_array, 0, n - 1);
  if(ret_val == -1) printf("0");
  else printf("1");
  free(input_array);
}
