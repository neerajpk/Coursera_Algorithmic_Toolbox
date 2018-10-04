#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct
{
  int arr_size;
  int* outp_arr;
  int* inpt_arr;
  int flag;
}struct_arr;

int primitive_calc(int, struct_arr*);
int min(int, int, int);

int min(int a, int b, int c)
{
  int min_val = INT_MAX;
  if(a < min_val) min_val = a;
  if(b < min_val) min_val = b;
  if(c < min_val) min_val = c;
  return min_val;
}

int primitive_calc(int n, struct_arr* obj)
{
  if(n == 1) return 0;
  if(obj -> inpt_arr[n - 1] != 0) return obj -> inpt_arr[n - 1];
  int temp_val1 = 0, temp_val2 = 0;
  obj -> inpt_arr[n - 1] = INT_MAX;
  if(n % 3 == 0)
  {
    temp_val1 = primitive_calc(n/3, obj);
    if(temp_val1 < obj -> inpt_arr[n - 1])
    {
      obj -> inpt_arr[n - 1] = temp_val1 + 1;
      temp_val2 = n/3;
    }
  }
  if(n % 2 == 0)
  {
    temp_val1 = primitive_calc(n/2, obj);
    if(temp_val1 < obj -> inpt_arr[n - 1])
    {
      obj -> inpt_arr[n - 1] = temp_val1 + 1;
      temp_val2 = n/2;
    }
  }
  temp_val1 = primitive_calc(n - 1, obj);
  if(temp_val1 < obj -> inpt_arr[n - 1])
  {
    obj -> inpt_arr[n - 1] = temp_val1 + 1;
    temp_val2 = n - 1;
  }
  printf("%d\t%d\n", n - 1, obj -> inpt_arr[n - 1]);
  if(obj -> inpt_arr[n - 1] >= obj -> arr_size)
  {
    obj -> outp_arr = (int*)realloc(obj -> outp_arr, obj -> inpt_arr[n - 1] * sizeof(int));
    obj -> arr_size = obj -> inpt_arr[n - 1];
    obj -> outp_arr[obj -> inpt_arr[n - 1] - 1] = temp_val2;
  }

  return obj -> inpt_arr[n - 1];
}

void main()
{
  int n;
  scanf("%d", &n);
  struct_arr* obj = (struct_arr*)malloc(sizeof(struct_arr));
  obj -> arr_size = 0;
  obj -> flag = 0;
  obj -> outp_arr = (int*)malloc(sizeof(int));
  obj -> inpt_arr = (int*)calloc(n, sizeof(int));
  // obj -> outp_arr[obj -> arr_size - 1] = n;
  int count = primitive_calc(n, obj);
  printf("\n%d\n", count);
  obj -> outp_arr = (int*)realloc(obj -> outp_arr, (count + 1) * sizeof(int));
  obj -> outp_arr[count] = n;
  for(int i = 0; i <= count; i++) printf("%d ", obj -> outp_arr[i]);
  free(obj);
}
