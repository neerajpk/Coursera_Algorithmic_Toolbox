#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

void swap(int*, int*);
void heapify(int*, int, int);
void heapsort(int*, int);

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void heapify(int *array, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < size && array[largest] < array[left]) largest = left;
    if(right < size && array[largest] < array[right]) largest = right;
    if(largest != index)
    {
        swap(&array[index], &array[largest]);
        heapify(array, size, largest);
    }
}

void heapsort(int *array, int arraySize)
{
    int i = (arraySize/2) - 1;
    for(;i >= 0; i--) heapify(array, arraySize, i);
    for(i = arraySize - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

void main()
{
  int arraySize = 0;
  int64_t product = 0;
  scanf("%d", &arraySize);
  int array[arraySize];
  for(int i = 0; i < arraySize; i++) scanf("%d",&array[i]);
  heapsort(array, arraySize);
  product = (int64_t)array[arraySize  - 1] * (int64_t)array[arraySize - 2];
  printf("%"PRId64,product);
}
