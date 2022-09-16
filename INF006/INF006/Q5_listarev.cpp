#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n = 10, l, c;
  int matriz[n][n];
  for (l = 0; l < n; l++)
  {
    for (c = 0; c < n; c++)
    {
      scanf("%d", &matriz[l][c]);
    }
  }
  for (l = 0, c = 0; l < n; l++, c++)
  {
    if (l + 1 < 4)
    {
      printf("%d\n", matriz[l + 1][c]);
    }
  }
}