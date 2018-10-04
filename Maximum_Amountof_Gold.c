#include<stdio.h>
#include<stdlib.h>

void maximum_amount_of_gold(int, int, int*, int**);

void maximum_amount_of_gold(int W, int n, int* weight_array, int** matrix)
{
  int temp_val = 0, i = 1, j = 1;
  for(i = 1; i < n; i++)
  {
    for(j = 1; j < W; j++)
    {
      matrix[i][j] = matrix[i - 1][j];
      if(weight_array[i - 1] <= j)
      {
        temp_val = matrix[i - 1][j - weight_array[i - 1]] + weight_array[i - 1];
        if(temp_val > matrix[i][j]) matrix[i][j] = temp_val;
      }
    }
  }
  printf("%d", matrix[i - 1][j - 1]);
}

void main()
{
  int W, n, i;
  scanf("%d %d", &W, &n);
  int* weight_array = (int*)calloc(n, sizeof(int));
  for(i = 0; i < n; i++) scanf("%d", &weight_array[i]);
  int** matrix = (int**)calloc(n + 1, sizeof(int*));
  for(i = 0; i <= n; i++) matrix[i] = (int*)calloc(W + 1, sizeof(int));
  maximum_amount_of_gold(W + 1, n + 1, weight_array, matrix);
}
