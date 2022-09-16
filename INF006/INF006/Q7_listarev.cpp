#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n = 5, l, c, i;
  int matriz[n][n], arrmaior[n], arrmenor[n];

  for (l = 0; l < n; l++)
  {
    for (c = 0; c < n; c++)
    {
      printf("digite l:%d c:%d\n", l + 1, c + 1);
      scanf("%d", &matriz[l][c]);
      if (c == 0)
      {
        arrmaior[l] = matriz[l][c];
        arrmenor[l] = matriz[l][c];
      }
      if (arrmaior[l] < matriz[l][c])
      {
        arrmaior[l] = matriz[l][c];
      }
      if (arrmenor[l] > matriz[l][c])
      {
        arrmenor[l] = matriz[l][c];
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    printf("maior: %d, menor: %d, a+b = %d\n", arrmaior[i], arrmenor[i], arrmaior[i] + arrmenor[i]);
  }
}