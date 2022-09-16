#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n = 10, i;

  int arrnums[n], arrnums2[n], result[n];
  char arrop[n+1];
  for (i = 0; i < n; i++)
  {
    printf("digite um num\n");
    scanf("%d", &arrnums[i]);
    getchar();
    printf("digite a operacao\n");
    scanf("%c", &arrop[i]);
    printf("digite um num\n");
    scanf("%d",& arrnums2[i]);
    if (arrop[i] == '+')
    {
      result[i] = arrnums[i] + arrnums2[i];
    }
    if (arrop[i] == '-')
    {
      result[i] = arrnums[i] - arrnums2[i];
    }
    if (arrop[i] == '*')
    {
      result[i] = arrnums[i] * arrnums2[i];
    }
    if (arrop[i] == '/')
    {
      result[i] = arrnums[i] / arrnums2[i];
    }
  }
  for (i = 0; i < n; i++)
  {
    printf("%d", result[i]);
  }
}