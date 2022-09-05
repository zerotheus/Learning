#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n, l, c, d1, d2, dif; 
  scanf("%d", &n);
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
    d1 = d1 + matriz[l][c];
  }
  for (l = 0, c = (n-1); l < n; l++, c--)
  {
    d2 = d2 + matriz[l][c];
  }
  dif=d1-d2;
  if (dif<0)
  {
    dif=dif*-1;
  }
  printf("%d", dif);
}