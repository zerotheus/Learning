#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int fatorial(int num)
{
  int f, multi=1;
  if (num == 1)
  {
    multi = num;
  }
  else
  {
    if (num < 1)
    {
      multi = -1;
    }
    if (num > 1)
    {
      for (f = 2; f <= num; f++)
      {
        multi=multi*f;
      }
    }
  }
  return multi;
}

int main()
{
  int n, result;
  printf("you know what do\n");
  scanf("%d", &n);
  result = fatorial(n);
  if (result<1)
  {
    printf("erro");
  }else{
    printf("%d", result);
  }
  
}