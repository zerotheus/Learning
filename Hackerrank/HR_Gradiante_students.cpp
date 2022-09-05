#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int aproxima(int arr)
{
  int soma = 0;
  if (arr >= 38 && arr % 5 != 0)
  {
    if (arr % 5 >= 3)
    {
      soma = arr % 5;
      soma = 5 - soma;
      arr = arr + soma;
    }
  }
  return arr;
}

void lernotas(int arr[], int n)
{
  arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
    arr[i] = aproxima(arr[i]);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int vetor[n];
  lernotas(vetor, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", vetor[i]);
  }
}