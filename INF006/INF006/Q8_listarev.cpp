#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n = 3, l, c, i, tri=0;
  int matriz[n][n];
  for (l = 0; l < n; l++)
  {
    for (c = 0; c < n; c++)
    {
      printf("digite l:%d c:%d\n", l + 1, c + 1);
      scanf("%d", &matriz[l][c]);
      if (l<c && matriz[l][c]==0)
      {
        tri=1;
      }
      if (l>c && matriz[l][c]!=0)
      {
        tri=1;
      }
    }
  }
  if (tri==1)
  {
    printf("nao e triangular");
  }
  if (tri==0)
  {
    printf("E triangular");
  }
}