#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

void sort(int arr[], int n)
{
  int i, j;
  int menor, aux = 0;
  for (i = 0; i < n - 1; i++)
  {
    menor = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[menor])
      {
        menor = j;
      }
    }
    aux = arr[i];
    arr[i] = arr[menor];
    arr[menor] = aux;
  }
}

int main()
{
  int n = 20, i, j, cont, k = 0;

  int arr[n], arr2[n];

  for (i = 0; i < n; i++)
  {
    printf("digite o %d elemento do vetor\n", i + 1);
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++)
  {
    cont = 0;
    for (j = 0; j < n; j++)
    {
      if (i != j && arr[i] == arr[j])
      {
        cont++;
      }
    }
    if (cont == 0)
    {
      arr2[k] = arr[i];
      k++;
    }
  }
  sort(arr2, k);
  for (i = 0; i < k; i++)
  {
    printf("%d", arr2[i]);
  }
}