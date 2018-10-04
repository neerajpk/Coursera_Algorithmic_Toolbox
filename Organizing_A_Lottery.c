#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void swap(int*, int*);
int* partition(int*, int*, int, int);
void three_way_quicksort(int*, int*, int, int);
void scan(int*, int*, int, int, int, int*);

void swap(int* p, int* q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

int* partition(int* seg_starts, int* seg_ends, int low, int high)
{
  int* partitions = (int*)malloc(2 * sizeof(int)), i = low;
  partitions[0] = low;
  partitions[1] = high;
  while(i <= partitions[1])
  {
    if(seg_ends[i] < seg_ends[partitions[0]])
    {
      swap(&seg_ends[i], &seg_ends[partitions[0]]);
      swap(&seg_starts[i++], &seg_starts[(partitions[0])++]);
    }
    else if(seg_ends[i] > seg_ends[partitions[0]])
    {
      swap(&seg_ends[i], &seg_ends[partitions[1]]);
      swap(&seg_starts[i], &seg_starts[(partitions[1])--]);
    }
    else i++;
  }
  return partitions;
}

void three_way_quicksort(int* seg_starts, int* seg_ends, int low, int high)
{
  if(low < high)
  {
    int temp = low + rand() % (high - low + 1);
    swap(&seg_starts[temp], &seg_starts[low]);
    swap(&seg_ends[temp], &seg_ends[low]);
    int* partitions = partition(seg_starts, seg_ends, low, high);
    three_way_quicksort(seg_starts, seg_ends, low, partitions[0] - 1);
    three_way_quicksort(seg_starts, seg_ends, partitions[1] + 1, high);
  }
}

void scan(int* seg_starts, int* seg_ends, int low, int high, int point, int* count)
{
  for(int i = high; i >= low; i--)
  {
    if(point > seg_ends[i]) break;
    if(point <= seg_ends[i] && point >= seg_starts[i]) (*count)++;
  }
}

void main()
{
  int ns, np, i, count;
  scanf("%d%d", &ns, &np);
  int seg_starts[ns], seg_ends[ns], points[np];
  for(i = 0; i < ns; i++) scanf("%d%d", &seg_starts[i], &seg_ends[i]);
  for(i = 0; i < np; i++) scanf("%d", &points[i]);
  three_way_quicksort(seg_starts, seg_ends, 0, ns - 1);
  for(i = 0; i < np; i++)
  {
    count = 0;
    scan(seg_starts, seg_ends, 0, ns - 1, points[i], &count);
    printf("%d ", count);
  }
}
