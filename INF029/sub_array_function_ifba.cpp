#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int sub(int valores[3], int count)//usar o tamanho como parametro antes de iniciar o vetor
{
  int sub = 0, i;
  for (i = 0; i < count; i++)
  {
    if (i == 0)
    {
      sub = valores[i];
    }
    else
    {
      sub = sub - valores[i];
    }
  }
  return sub;
}

int main()
{
  int n = 3, val[n], result;
  printf("You know what to do \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &val[i]);
  }
  result = sub(val, n);
  printf("%d", result);
}