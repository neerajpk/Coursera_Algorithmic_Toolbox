#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void long_common_sub3(int*, int, int*, int, int*, int, int***);
int max(int*);

int max(int* arr)
{
  int max_val = INT_MIN;
  for(int i = 0; i < 6; i++) max_val = ((arr[i] > max_val) ? arr[i] : max_val);
  return max_val;
}

void long_common_sub3(int* arr1, int n1, int* arr2, int n2, int* arr3, int n3, int*** matrix)
{
  matrix = (int***)calloc(n1, sizeof(int**));
  int i = 0, j = 0, k = 0;
  for(i = 0; i < n1; i++)
  {
    matrix[i] = (int**)calloc(n2, sizeof(int*));
    for(j = 0; j < n2; j++) matrix[i][j] = (int*)calloc(n3, sizeof(int));
  }
  for(i = 1; i < n1; i++)
  {
    for(j = 1; j < n2; j++)
    {
      for(k = 1; k < n3; k++)
      {
        int temp_arr[6];
        temp_arr[0] = matrix[i - 1][j][k];
        temp_arr[1] = matrix[i - 1][j][k];
        temp_arr[2] = matrix[i][j - 1][k];
        temp_arr[3] = matrix[i][j - 1][k];
        temp_arr[4] = matrix[i][j][k - 1];
        temp_arr[5] = matrix[i][j][k - 1];
        if((arr1[i - 1] != arr2[j - 1])||(arr2[j - 1] != arr3[k - 1])||(arr3[k - 1] != arr1[i - 1])) matrix[i][j][k] = max(temp_arr);
        else matrix[i][j][k] = matrix[i - 1][j - 1][k - 1] + 1;
      }
    }
  }
  printf("%d", matrix[i - 1][j - 1][k - 1]);
}

void main()
{
  int n1, n2, n3, i = 0;
  scanf("%d", &n1);
  int* arr1 = (int*)calloc(n1, sizeof(int));
  for(i = 0; i < n1; i++) scanf("%d", &arr1[i]);
  scanf("%d", &n2);
  int* arr2 = (int*)calloc(n2, sizeof(int));
  for(i = 0; i < n2; i++) scanf("%d", &arr2[i]);
  scanf("%d", &n3);
  int* arr3 = (int*)calloc(n3, sizeof(int));
  for(i = 0; i < n3; i++) scanf("%d", &arr3[i]);
  int*** matrix;
  long_common_sub3(arr1, n1 + 1, arr2, n2 + 1, arr3, n3 + 1, matrix);
  free(arr1);
  free(arr2);
  free(arr3);
  free(matrix);
}
