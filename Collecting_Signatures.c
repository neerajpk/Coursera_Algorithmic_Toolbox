/*Task. Given a set of n segments {[a0, b0], [a1, b1], . . . , [an−1, bn−1]} with integer coordinates on a line, fnd
the minimum number m of points such that each segment contains at least one point. That is, fnd a
set of integers X of the minimum size such that for any segment [ai, bi] there is a point x ∈ X such
that ai ≤ x ≤ bi.
Input Format. The frst line of the input contains the number n of segments. Each of the following n lines
contains two integers ai and bi (separated by a space) defning the coordinates of endpoints of the i-th
segment.
Constraints. 1 ≤ n ≤ 100; 0 ≤ ai ≤ bi ≤ 109 for all 0 ≤ i < n.
Output Format. Output the minimum number m of points on the frst line and the integer coordinates
of m points (separated by spaces) on the second line. You can output the points in any order. If there
are many such sets of points, you can output any set. (It is not difcult to see that there always exist
a set of points of the minimum size such that all the coordinates of the points are integers.)*/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  int n, m;
  int *start_point_array, *end_point_array, *m_coords;
}dataset;


void swap(int*, int*);
int partition(dataset*, int, int);
void quicksort(dataset*, int, int);
void collecting_signatures(dataset*);

void swap(int *p, int *q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

int partition(dataset *obj, int low, int high)
{
  int pivot = obj -> start_point_array[high];
  int i = low - 1;
  for(int j = low; j <= high - 1; j++)
  {
    if(obj -> start_point_array[j] <= pivot)
    {
      i++;
      swap(&(obj -> start_point_array[i]), &(obj -> start_point_array[j]));
      swap(&(obj -> end_point_array[i]), &(obj -> end_point_array[j]));
    }
  }
  swap(&(obj -> start_point_array[i + 1]), &(obj -> start_point_array[high]));
  swap(&(obj -> end_point_array[i + 1]), &(obj -> end_point_array[high]));
  return i + 1;
}

void quicksort(dataset *obj, int low, int high)
{
  if(low < high)
  {
    int p = partition(obj, low, high);
    quicksort(obj, low, p - 1);
    quicksort(obj, p + 1, high);
  }
}

void collecting_signatures(dataset* obj)
{
  int i = 1, temp_m = obj -> end_point_array[0];
  obj -> m = 0;
  while(i < obj -> n)
  {
    if(temp_m < obj -> start_point_array[i] || temp_m > obj -> end_point_array[i])
    {
      if(temp_m > obj -> end_point_array[i])
      {
        temp_m = obj -> end_point_array[i];
        if(i < (obj -> n) - 1) continue;
      }
      obj -> m_coords = (int*)realloc(obj -> m_coords, ++(obj -> m) * sizeof(int));
      obj -> m_coords[(obj -> m) - 1] = temp_m;
      temp_m = obj -> end_point_array[i];
    }
    i++;
  }
  if(obj -> m == 0 || (obj -> m > 0 && obj -> m_coords[(obj -> m) - 1] != temp_m))
  {
    obj -> m_coords = (int*)realloc(obj -> m_coords, ++(obj -> m) * sizeof(int));
    obj -> m_coords[(obj -> m) - 1] = temp_m;
  }
}

void main()
{
  dataset *obj = (dataset*)malloc(sizeof(dataset));
  scanf("%d", &(obj -> n));
  obj -> start_point_array = (int*)calloc(obj -> n, sizeof(int));
  obj -> end_point_array = (int*)calloc(obj -> n, sizeof(int));
  obj -> m_coords = (int*)malloc(sizeof(int));
  for(int i = 0; i < obj -> n; i++) scanf("%d %d", &(obj -> start_point_array[i]), &(obj -> end_point_array[i]));
  quicksort(obj, 0 , obj -> n - 1);
  collecting_signatures(obj);
  printf("%d\n", obj -> m);
  for(int i = 0; i < obj -> m; i++) printf("%d\t", obj -> m_coords[i]);
  free(obj);
}
