/******************************************************************************
Criar um programa que deixe entrar com nome e idade de 20 pessoas e
armazene em um vetor todos os nomes que comecem com a letra no
intervalo L-S
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
  char nome[20][15], LtoS[20][15];
  int idade[20], j = -1;
  for (int i = 0; i < 20; i++)
  {
    printf("Digite um nome: ");
    fgets(nome[i], 14, stdin); // nome[i],14,stdin
    printf("Digite uma idade: \n");
    scanf("%d", &idade[i]);
    getchar();
  }

  for (int i = 0; i < 20; i++)
  {
    if ((nome[i][0] > 75 && nome[i][0] < 84) || (nome[i][0] > 107 && nome[i][0] < 116))
    {
      j++;
      puts(nome[i]);
      strcpy(LtoS[j], nome[i]);
    }
  }
  for (int i = 0; i <= j; i++)
  {
    puts(LtoS[i]);
  }
}
