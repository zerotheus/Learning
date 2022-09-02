#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
/*Entrar com a idade de varias pessoas ate o usuário informar que deseja
parar. e imprimir o total de pessoas com menos de 21 e total de pessoas
maiores que 50*/
int main()
{
  int veio = 0, demenor = 0, idade = 0;
  while (idade >= 0)
  {
    printf("informe a idade, informe uma idade negativa para parar\n");
    scanf("%d",& idade);
    if (idade < 21 && idade>=0)
    {
      demenor++;
    }
    if (idade > 50)
    {
      veio++;
    }
  }
  printf("veio %d\n demenores %d \n", veio, demenor);
}