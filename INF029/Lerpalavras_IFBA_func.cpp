#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

void get_input(char *input, int lim)
{
  char palavra[lim];
  printf("digite a palavra");
  fgets(palavra, (lim - 1), stdin);
  for (int i = 0; palavra[i] != '\0'; i++)
  {
    input[i] = palavra[i];
  }
}

int main()
{
  int n = 3, lim = 31, i;
  char palavras[n][lim];
  for (i = 0; i < n; i++)
  {
    get_input(palavras[i], lim);
  }
  for (i = 0; i < n; i++)
  {
    puts(palavras[i]);
  }
  
}