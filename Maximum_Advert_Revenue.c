/*Task. Given two sequences a1, a2, . . . , an (ai is the profit per click of the i-th ad) and b1, b2, . . . , bn (bi is
the average number of clicks per day of the i-th slot), we need to partition them into n pairs (aj, bj)
such that the sum of their products is maximized.
Input Format. The frst line contains an integer n, the second one contains a sequence of integers
a1, a2, . . . , an, the third one contains a sequence of integers b1, b2, . . . , bn.
Constraints. 1 ≤ n ≤ 10^3; −10^5 ≤ ai, bi ≤ 10^5 for all 1 ≤ i ≤ n.
Output Format. Output the maximum value of ∑(ai,ci), where c1, c2, . . . , cn is a permutation of b1, b2, . . . , bn.*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

typedef struct
{
  int n;
  int64_t *profit_per_click_array;
  int64_t *avg_num_clicks_per_day_array;
}dataset;

void swap(int64_t*, int64_t*);
int partition(int64_t*, int, int);
void quicksort(int64_t*, int, int);
int64_t max_ad_rev(dataset*);

void swap(int64_t* p, int64_t* q)
{
  int64_t temp = *p;
  *p = *q;
  *q = temp;
}

int partition(int64_t* array, int low, int high)
{
  int64_t pivot = array[high];
  int i = low - 1;
  for(int j = low; j <= high - 1; j++)
  {
    if(array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return i + 1;
}

void quicksort(int64_t* array, int low, int high)
{
  if(low < high)
  {
    int p = partition(array, low, high);
    quicksort(array, low, p - 1);
    quicksort(array, p + 1, high);
  }
}

int64_t max_ad_rev(dataset *obj)
{
  int i = (obj -> n) - 1;
  int64_t max_rev = 0;
  while(i >= 0) max_rev += obj -> profit_per_click_array[i] * obj -> avg_num_clicks_per_day_array[i--];
  return max_rev;
}

void main()
{
  dataset *obj = (dataset*)malloc(sizeof(dataset));
  scanf("%d", &(obj -> n));
  obj -> profit_per_click_array = (int64_t*)calloc(obj -> n, sizeof(int64_t));
  obj -> avg_num_clicks_per_day_array = (int64_t*)calloc(obj -> n, sizeof(int64_t));
  for(int i = 0; i < obj -> n; i++) scanf("%"PRId64, &(obj -> profit_per_click_array[i]));
  for(int i = 0; i < obj -> n; i++) scanf("%"PRId64, &(obj -> avg_num_clicks_per_day_array[i]));
  quicksort(obj -> profit_per_click_array, 0, (obj -> n) - 1);
  quicksort(obj -> avg_num_clicks_per_day_array, 0, (obj -> n) - 1);
  printf("%"PRId64, max_ad_rev(obj));
  free(obj);
}
