#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

void ler3letras(char *input)
{
  char letra;
  for (int i = 0; i < 3; i++)
  {
    printf("digite\n");
    scanf("%c", &letra);
    getchar();
    input[i] = letra;
  }
}

int main()
{
  char letras[3];
  ler3letras(letras);
  for (int i = 0; i < 3; i++)
  {
    printf("letras: %c ", letras[i]);
  }
}