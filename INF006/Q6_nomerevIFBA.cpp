#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
/*Armazenar nomes e nota 1, 2, de 15 alunos. calcular e armazenar a media.
armazenar tambem a situação do aluno: AP ou RP. imprimir uma listagem
contendo nome, notas, media e a situação de cada aluno.
*/
int main()
{
  int n = 15;
  char nome[n][20];
  int j, i;
  float nota[n][30], media[n], sit[n];
  for (i = 0; i < n; i++)
  {
    printf("digite o nome\n");
    fgets(nome[i], 19, stdin);
    for (j = 0; j < 2; j++)
    {
      printf("Digite a %d nota\n", j);
      scanf("%f", &nota[i][j]);
    }
    getchar();
    media[i] = (nota[i][0] + nota[i][1]) / 2;
    if (media[i] < 5)
    {
      sit[i] = 0;
    }
    else
    {
      sit[i] = 1;
    }
  }
  for (i = 0; i < n; i++)
  {
    if (sit[i] == 0)
    {
      puts(nome[i]);
      for (j = 0; j < 2; j++)
      {
        printf("nota %d: %f\t", j, nota[i][j]);
      }
      printf("\nmedia %f", media[i]);
      printf("\nreprovado\n");
    }
    else
    {
      puts(nome[i]);
      for (j = 0; j < 2; j++)
      {
        printf("nota %d: %f\t", j, nota[i][j]);
      }
      printf("\nmedia %f", media[i]);
      printf("\naprovado\n");
    }
  }
}