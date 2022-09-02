#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
/*Chico tem 1.50m e cresce 2 centímetros por ano, enquanto Juca tem 1.10m e
cresce 3 cm por ano. construir um programa que calcule e imprima
quantos anos serão necessários para Juca seja maior que Chico;*/
int main()
{
  int chico=150, fran=110, ano;
  for (ano = 0; chico>=fran; fran=fran+3,chico=chico+2,ano++)
  {
  }
  printf("%d anos", ano);
}