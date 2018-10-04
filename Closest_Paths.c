#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

void swap(int*, int*);
int* partition(int**, int, int, int);
void three_way_quicksort(int**, int, int, int);
void find_min_distance(int**, int, int, double*);

void swap(int* p, int* q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

int* partition(int** points, int sort_index, int low, int high)
{
  int* partitions = (int*)malloc(2 * sizeof(int)), i = low;
  partitions[0] = low;
  partitions[1] = high;
  while(i <= partitions[1])
  {
    if(points[i][sort_index] < points[partitions[0]][sort_index])
    {
      swap(&points[i][sort_index], &points[partitions[0]][sort_index]);
      swap(&points[i++][sort_index ^ 1], &points[(partitions[0])++][sort_index ^ 1]);
    }
    else if(points[i][sort_index] > points[partitions[0]][sort_index])
    {
      swap(&points[i][sort_index], &points[partitions[1]][sort_index]);
      swap(&points[i][sort_index], &points[(partitions[1])--][sort_index]);
    }
    else i++;
  }
  return partitions;
}

void three_way_quicksort(int** points, int sort_index, int low, int high)
{
  if(low < high)
  {
    int temp = low + rand() % (high - low + 1);
    swap(&points[temp][sort_index], &points[low][sort_index]);
    swap(&points[temp][sort_index ^ 1], &points[low][sort_index ^ 1]);
    int* partitions = partition(points, sort_index, low, high);
    three_way_quicksort(points, sort_index, low, partitions[0] - 1);
    three_way_quicksort(points, sort_index, partitions[1] + 1, high);
  }
}

void find_min_distance(int** points, int low, int high, double* distance)
{
  if(low < high)
  {
    int mid = low + (int)ceil((float)((high - low)/2));
    double temp_x, temp_y, temp_dist;
    if(mid - low == 1)
    {
      temp_x = points[mid][0] - points[low][0];
      temp_y = points[mid][1] - points[low][1];
      temp_dist = sqrt((temp_x * temp_x) + (temp_y * temp_y));
      if(temp_dist < *distance) *distance = temp_dist;
    }
    else find_min_distance(points, low, mid, distance);
    if(high - mid == 1)
    {
      temp_x = points[high][0] - points[mid][0];
      temp_y = points[high][1] - points[mid][1];
      temp_dist = sqrt(temp_x * temp_x + temp_y * temp_y);
      if(temp_dist < *distance) *distance = temp_dist;
    }
    else find_min_distance(points, mid, high, distance);
    if(mid - low == 1 && high - mid == 1)
    {
      if(abs(points[mid][0] - points[low][0]) <= *distance && abs(points[high][0] - points[mid][0]) <= *distance)
      {
        temp_x = points[high][0] - points[low][0];
        temp_y = points[high][1] - points[low][1];
        temp_dist = sqrt(temp_x * temp_x + temp_y * temp_y);
        if(temp_dist < *distance) *distance = temp_dist;
      }
    }
  }
}

void main()
{
  int np, i;
  double distance = 1000000001;
  scanf("%d", &np);
  int** points = (int**)malloc(np * sizeof(int*));
  for(i = 0; i < np; i++)
  {
    points[i] = (int*)malloc(2 * sizeof(int));
    scanf("%d %d", &points[i][0], &points[i][1]);
  }
  three_way_quicksort(points, 0, 0, np - 1);
  find_min_distance(points, 0, np - 1, &distance);
  printf("%lf", distance);
  free(points);
}
