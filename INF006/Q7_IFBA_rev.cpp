#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n = 5, lim = 5;
  int arr[n], vet[lim], comum[10], verifica = 0, elementos = 0;
  for (int i = 0; i < n; i++)
  {
    printf("digite os elementos do vetor %d\n", i);
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < lim; i++)
  {
    printf("digite os elementos do seg vetor %d", i);
    scanf("%d", &vet[i]);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < lim; j++)
    {
      if (arr[i] == vet[j])
      {
        for (int k = 0, verifica = 0; k < n; k++)
        {
          if (arr[i] == comum[k])
          {
            verifica = 1;
          }
        }
        if (verifica == 0)
        {
          comum[elementos] = arr[i];
          elementos++;
        }
      }
      else
      {
        break;
      }
    }
  }
  for (int i = 0; i <= elementos; i++)
  {
    printf("elemento em comum %d\n", comum[i]);
  }
}