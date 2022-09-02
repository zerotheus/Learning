#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

/*Criar e armazenar ua matriz a 10x10 e gerar e imprimir a matriz invertida*/

int main()
{
  int linha = 10;
  int matriz[linha][linha], l, c;

  for (l = 0; l < linha; l++)
  {
    printf("digite um num");
    for (c = 0; c < linha; c++)
    {
      scanf("%d", &matriz[l][c]);
    }
    printf("\n");
  }
  for (l = linha - 1; l >= 0; l--)
  {
    for (c = linha - 1; c >= 0; c--)
    {
      printf(" %d ", matriz[l][c]);
    }
    printf("\n");
  }
}