#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool check_sum(int*, int, int*);
void partitioning_souvenirs(int***, int*, int, int);

void partitioning_souvenirs(int*** matrix, int* arr, int n, int sum)
{
  int i = 0, j = 0, k = 0, temp1 = 0, temp2 = 0;
  for(k = 2; k < n; k++)
  {
    for(i = 0; i < sum; i++)
    {
      for(j = 0; j < sum; j++)
      {
        temp1 = ((arr[k - 1] <= i) ? matrix[k - 1][i - arr[k - 1]][j] : 0);
        temp2 = ((arr[k - 1] <= j) ? matrix[k - 1][i][j - arr[k - 1]] : 0);
        matrix[k][i][j] = matrix[k - 1][i][j] || temp1 || temp2;
      }
    }
  }
  if(matrix[k - 1][i - 1][j - 1] == 1) printf("1");
  else printf("0");
}

bool check_sum(int* arr, int n, int* sum)
{
  for(int i = 0; i < n; i++) *sum += arr[i];
  return ((*sum % 3 == 0) ? true : false);
}

void main()
{
    int n, i = 0, j = 0, sum = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    if(!check_sum(arr, n, &sum))
    {
      free(arr);
      printf("0");
      return;
    }
    int*** matrix = (int***)calloc(n + 1, sizeof(int**));
    for(i = 0; i <= n; i++)
    {
      matrix[i] = (int**)calloc(sum/3 + 1, sizeof(int*));
      for(j = 0; j <= sum/3; j++)
      {
        matrix[i][j] = (int*)calloc(sum/3 + 1, sizeof(int));
        if(j == 0) matrix[i][j][0] = 1;
        if(j == arr[0]) matrix[i][j][0] = 1;
      }
    }
    matrix[1][0][arr[0]] = 1;
    partitioning_souvenirs(matrix, arr, n + 1, sum/3 + 1);
    free(arr);
    free(matrix);
}
