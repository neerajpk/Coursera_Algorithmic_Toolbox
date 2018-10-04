#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* min_and_max(int i, int j)

int paranthesis(int* min_array, int* max_array, int size, )

void main()
{
    int i = 0, n = 0;
    char inp_str[29];
    scanf("%s", &inp_str);
    n = strlen(inp_str);
    int* symb_array = (int*)malloc((n/2 + 1) * sizeof(int));
    for(i = 0; i < n; i++) if(i % 2 == 0) symb_array[i/2] = inp_str[i] - '0';
    free(symb_array);
}
