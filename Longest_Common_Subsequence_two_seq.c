#include<stdio.h>
#include<stdlib.h>

void long_common_sub2(int*, int, int*, int, int**);

void long_common_sub2(int* arr1, int n1, int* arr2, int n2, int** matrix)
{
  matrix = (int**)calloc(n1, sizeof(int*));
  int i = 0, j = 0;
  for(; i < n1; i++)
  {
    matrix[i] = (int*)calloc(n2, sizeof(int));
    matrix[i][0] = 0;
  }
  for(i = 0; i < n2; i++) matrix[0][i] = 0;
  for(i = 1; i < n1; i++)
  {
    for(j = 1; j < n2; j++)
    {
      if(arr1[i - 1] != arr2[j - 1]) matrix[i][j] = ((matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1]);
      else matrix[i][j] = matrix[i - 1][j - 1] + 1;
    }
  }
  printf("%d", matrix[i - 1][j - 1]);
}

void main()
{
  int n1, n2, i = 0;
  scanf("%d", &n1);
  int* arr1 = (int*)calloc(n1, sizeof(int));
  for(i = 0; i < n1; i++) scanf("%d", &arr1[i]);
  scanf("%d", &n2);
  int* arr2 = (int*)calloc(n2, sizeof(int));
  for(i = 0; i < n2; i++) scanf("%d", &arr2[i]);
  int** matrix;
  long_common_sub2(arr1, n1 + 1, arr2, n2 + 1, matrix);
  free(arr1);
  free(arr2);
  free(matrix);
}
