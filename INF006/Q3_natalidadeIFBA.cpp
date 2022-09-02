#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

/*Dado um pais A, com 5.000.000 de habitantes e uma taxa de natalidade de
3% ao ano, e um pais B com 7.000.000 de habitantes e uma taxa de
natalidade de 2% ao ano. calcular e imprimir o tempo necessário para que
a população do pais A ultrapasse a população do pais B*/

int main()
{
  long int A = 5000000, B = 7000000;
  int ano;
  for (ano = 0;B>=A; ano++)
  {
    A=A*1.03;
    B=B*1.02;
  }
  printf("tempo necessario %d anos", ano);
}