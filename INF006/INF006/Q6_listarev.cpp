#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n = 10, l, c;
  int matriz[n][n], trocalinha[n];

  for (l = 0; l < n; l++)
  {
    for (c = 0; c < n; c++)
    {
      printf("digite l:%d c:%d\n", l + 1, c + 1);
      scanf("%d", &matriz[l][c]);
    }
  }
  for (l = 1, c = 0; c < n; c++) // troca das linhas
  {
    trocalinha[c] = matriz[l][c];    // salva linha
    matriz[l][c] = matriz[l + 6][c]; // linha salva + (linha de troca - linha base)
    matriz[l + 6][c] = trocalinha[c];
  }
  for (l = 3, c = 0; c < n; c++) // troca das linhas
  {
    trocalinha[c] = matriz[l][c];    // salva linha
    matriz[l][c] = matriz[l + 6][c]; // linha salva + (linha de troca - linha base)
    matriz[l + 6][c] = trocalinha[c];
  }
  for (l = 0, c = 0; c < n; l++, c++) // troca das diagonais
  {
    trocalinha[c] = matriz[l][c];          // salva linha
    matriz[l][c] = matriz[(n - 1) - l][c]; // linha salva + (linha de troca - linha base)
    matriz[(n - 1) - l][c] = trocalinha[c];
  }

  for (l = 0; l < n; l++)
  {
    for (c = 0; c < n; c++)
    {
      printf("%d", matriz[l][c]);
    }
    printf("\n");
  }
}