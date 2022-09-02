#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

/*Na usina de Angra dos Reis, os técnicos analisam a perda de massa de um
material radioativo. Sabendo-se que este perde 25% de sua massa a cada
30 segundos, criar um programa que imprima o tempo necessário para que a
massa deste material se torne menor que 0,10 gramas. O programa pode
calcular o tempo para varias massas.
*/

int main()
{
  int i;
  float massa;
  while (massa != 0)
  {
    printf("digite a massa\n");
    scanf("%f", &massa);
    for (i = 0; massa >= 0.1; i++)
    {
      massa=massa*0.75;
    }
    printf("tempo decorrido: %d segundos\n", i*30);
  }
}