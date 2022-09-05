#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n, deg, i, j;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (j<n-i)
      {
        printf(" ");
      }else{
        printf("#");
      }
      
    }
    printf("\n");
  }
}