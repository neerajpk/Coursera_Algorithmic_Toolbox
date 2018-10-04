/*Task. The goal of this code problem is to implement an algorithm for the fractional knapsack problem.
Input Format. The frst line of the input contains the number n of items and the capacity W of a knapsack.
The next n lines defne the values and weights of the items. The i-th line contains integers vi and wi—the
value and the weight of i-th item, respectively.
Constraints. 1 ≤ n ≤ 103, 0 ≤ W ≤ 2 · 10^6; 0 ≤ vi ≤ 2 · 106, 0 < wi ≤ 2 · 106 for all 1 ≤ i ≤ n. All the
numbers are integers.
Output Format. Output the maximal value of fractions of items that ft into the knapsack. The absolute
value of the diﬀerence between the answer of your program and the optimal value should be at most
10−3. To ensure this, output your answer with at least four digits after the decimal point (otherwise
your answer, while being computed correctly, can turn out to be wrong because of rounding issues).*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
  int n, W;
  int *value_array;
  int *weight_array;
  double *fractional_value_array;
}dataset;

void swap_int(int*, int*);
void swap_double(double*, double*);
int partition(dataset*, int, int);
void quicksort(dataset*, int, int);
double max_value_of_loot(dataset*);

void swap_double(double* p, double* q)
{
  double temp = *p;
  *p = *q;
  *q = temp;
}

void swap_int(int* p, int* q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

int partition(dataset *obj, int low, int high)
{
  double pivot = obj -> fractional_value_array[high];
  int i = low - 1;
  for(int j = low; j <= high - 1; j++)
  {
    if(obj -> fractional_value_array[j] <= pivot)
    {
      i++;
      swap_double(&(obj -> fractional_value_array[i]), &(obj -> fractional_value_array[j]));
      swap_int(&(obj -> value_array[i]), &(obj -> value_array[j]));
      swap_int(&(obj -> weight_array[i]), &(obj -> weight_array[j]));
    }
  }
  swap_double(&(obj -> fractional_value_array[i + 1]), &(obj -> fractional_value_array[high]));
  swap_int(&(obj -> value_array[i + 1]), &(obj -> value_array[high]));
  swap_int(&(obj -> weight_array[i + 1]), &(obj -> weight_array[high]));
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

double max_value_of_loot(dataset *obj)
{
  double max_value = 0;
  int i = (obj -> n) - 1;
  while(obj -> W > 0 && i >= 0)
  {
    if(obj -> weight_array[i] <= obj -> W)
    {
      max_value += obj -> value_array[i];
      obj -> W -= obj -> weight_array[i];
    }
    else
    {
      max_value += ((double)(obj -> W) / (double)(obj -> weight_array[i])) * obj -> value_array[i];
      break;
    }
    i--;
  }
  return max_value;
}

void main()
{
  dataset *obj = (dataset*)malloc(sizeof(dataset));
  scanf("%d %d", &(obj -> n), &(obj -> W));
  obj -> value_array = (int*)calloc(obj -> n, sizeof(int));
  obj -> weight_array = (int*)calloc(obj -> n, sizeof(int));
  obj -> fractional_value_array = (double*)calloc(obj -> n, sizeof(double));
  for(int i = 0; i < obj -> n; i++)
  {
    scanf("%d %d", &(obj -> value_array[i]), &(obj -> weight_array[i]));
    obj -> fractional_value_array[i] = (double)(obj -> value_array[i])/(double)(obj -> weight_array[i]);
  }
  quicksort(obj, 0, (obj -> n) - 1);
  printf("%.4f", max_value_of_loot(obj));
  free(obj);
}
