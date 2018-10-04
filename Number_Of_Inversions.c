#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void merge(int*, int, int, int, int*);
void mergesort(int*, int, int, int*);

void merge(int* input_array, int low, int mid, int high, int* inv_count)
{
  int n1 = mid - low + 1, n2 = high - mid, i = 0, j = 0, k = low;
  int* temp1 = (int*)malloc(n1 * sizeof(int));
  int* temp2 = (int*)malloc(n2 * sizeof(int));
  for(i = 0; i < n1; i++) temp1[i] = input_array[low + i];
  for(j = 0; j < n2; j++) temp2[j] = input_array[mid + j + 1];
  for(i = 0; i < n1; i++) for(j = 0; j < n2; j++) if(temp1[i] > temp2[j]) ++(*inv_count);
  i = 0, j = 0;
  while(i < n1 && j < n2)
  {
    if(temp1[i] < temp2[j]) input_array[k++] = temp1[i++];
    else input_array[k++] = temp2[j++];
  }
  while(i < n1) input_array[k++] = temp1[i++];
  while(j < n2) input_array[k++] = temp2[j++];
  free(temp1);
  free(temp2);
}

void mergesort(int* input_array, int low, int high, int* inv_count)
{
  if(low < high)
  {
    int mid = (low + high)/2;
    mergesort(input_array, low, mid, inv_count);
    mergesort(input_array, mid + 1, high, inv_count);
    merge(input_array, low, mid, high, inv_count);
  }
}

void main()
{
  int n, inv_count = 0;
  scanf("%d", &n);
  int* input_array = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) scanf("%d", &input_array[i]);
  mergesort(input_array, 0, n - 1, &inv_count);
  printf("%d", inv_count);
  free(input_array);
}
