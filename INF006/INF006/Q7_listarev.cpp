#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n = 3, l, c, i;
  int matriz[n][n], arrmaior[n], arrmenor[n];
  int maior = 0, menor = 0;
  for (l = 0; l < n; l++)
  {
    for (c = 0; c < n; c++)
    {
      printf("digite l:%d c:%d\n", l + 1, c + 1);
      scanf("%d", &matriz[l][c]);
      if (l == 0)
      {
        arrmaior[c] = matriz[l][c];
        arrmenor[c] = matriz[l][c];
      }
      if (arrmaior[c] < matriz[l][c])
      {
        arrmaior[c] = matriz[l][c];
      }
      if (arrmenor[c] > matriz[l][c])
      {
        arrmenor[c] = matriz[l][c];
      }
    }
  }
  for(i = 0; i < n; i++){
      
      maior += arrmaior[i];
      menor += arrmenor[i];
  }
   for (l = 0; l < n; l++)
  {
    for (c = 0; c < n; c++)
    {
      printf("%d", matriz[l][c]);
    }
      printf("printf\n");
  }
  for (i = 0; i < n; i++)
  {
    printf("maior: %d, menor: %d, a+b = %d\n", arrmaior[i], arrmenor[i], (maior + menor)/2);
  }
    
}
