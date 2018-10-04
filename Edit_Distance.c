#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

void cal_edit_distance(char*, int, char*, int, int**);
int min(int*);

int min(int* arr)
{
  int min_val = INT_MAX;
  for(int i = 0; i < 3; i++) if(arr[i] < min_val) min_val = arr[i];
  return min_val;
}

void cal_edit_distance(char* string1, int str1_len, char* string2, int str2_len, int** matrix)
{
  matrix = (int**)calloc(str1_len, sizeof(int*));
  int i = 0, j = 0, temp_arr[3];
  for(; i < str1_len; i++)
  {
    matrix[i] = (int*)calloc(str2_len, sizeof(int));
    matrix[i][0] = i;
  }
  for(i = 0; i < str2_len; i++) matrix[0][i] = i;
  for(i = 1; i < str1_len; i++)
  {
    for(j = 1; j < str2_len; j++)
    {
      temp_arr[0] = matrix[i - 1][j] + 1;
      temp_arr[1] = matrix[i][j - 1] + 1;
      temp_arr[2] = matrix[i - 1][j - 1];
      if(string1[i - 1] != string2[j - 1])
      {
        temp_arr[2] = temp_arr[2] + 1;
        matrix[i][j] = min(temp_arr);
      }
      else matrix[i][j] = min(temp_arr);
    }
  }
  printf("%d", matrix[i - 1][j - 1]);
}

void main()
{
  char string1[100], string2[100];
  scanf("%s", &string1);
  scanf("%s", &string2);
  int** matrix;
  int str1_len = strlen(string1) + 1, str2_len = strlen(string2) + 1;
  cal_edit_distance(string1, str1_len, string2, str2_len, matrix);
  free(matrix);
}
