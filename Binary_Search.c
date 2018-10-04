#include<stdio.h>
#include<math.h>

int binary_search(int*, int, int, int);

int binary_search(int* input_array, int low, int high, int search_val)
{
  if(low > high) return -1;
  int mid = low + ceil((high - low)/2);
  if(search_val == input_array[mid]) return mid;
  else if(search_val < input_array[mid]) binary_search(input_array, low, mid - 1, search_val);
  else binary_search(input_array, mid + 1, high, search_val);
}

void main()
{
  int n, k, i;
  scanf("%d", &n);
  int input_array[n];
  for(i = 0; i < n; i++) scanf("%d", &input_array[i]);
  scanf("%d", &k);
  int search_array[k];
  for(i = 0; i < k; i++) scanf("%d", &search_array[i]);
  for(i = 0; i < k; i++) printf("%d\t", binary_search(input_array, 0, n - 1, search_array[i]));
}
