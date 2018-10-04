#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int*, int*);
int* partition(int*, int, int);
void three_way_quicksort(int*, int, int);

void swap(int* p, int* q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

/*Using Dijkstra's 3 way partitioning demo*/
int* partition(int* input_array, int low, int high)
{
  int* partitions = (int*)malloc(2 * sizeof(int)), i = low;
  partitions[0] = low;
  partitions[1] = high;
  while(i <= partitions[1])
  {
    if(input_array[i] < input_array[partitions[0]]) swap(&input_array[(partitions[0])++], &input_array[i++]);
    else if(input_array[i] > input_array[partitions[0]]) swap(&input_array[(partitions[1])--], &input_array[i]);
    else if(input_array[i] == input_array[partitions[0]]) i++;
  }
  return partitions;
}

void three_way_quicksort(int* input_array, int low, int high)
{
  if(low < high)
  {
    swap(&input_array[low + rand() % (high - low + 1)], &input_array[low]);
    int* partitions = partition(input_array, low, high);
    three_way_quicksort(input_array, low, partitions[0] - 1);
    three_way_quicksort(input_array, partitions[1] + 1, high);
  }
}

void main()
{
  int n;
  scanf("%d", &n);
  int* input_array = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) scanf("%d", &input_array[i]);
  three_way_quicksort(input_array, 0, n - 1);
  for(int i = 0; i < n; i++) printf("%d ", input_array[i]);
  free(input_array);
}
