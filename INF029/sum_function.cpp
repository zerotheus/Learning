#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int sum(int x, int y)
{
  int sum;
  sum=x+y;
  return sum;
}

int main()
{
  int a, b, soma;
  printf("valor 1");
  scanf("%d", &a);
  printf("valor 2");
  scanf("%d", &b);
  soma=sum(a,b);
  printf("%d", soma);
}