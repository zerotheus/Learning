#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

struct numeros
{
  int numero;
} numeros[4];

int get_input()
{
  int input;
  scanf("%d", &input);
  return input;
}

int main()
{
  int i;
  for (i = 0; i < 4; i++)
  {
    printf("digite numero");
    numeros[i].numero = get_input();
  }
  for (i = 0; i < 4; i++)
  {
    printf("Num %d", numeros[i].numero);
  }
}