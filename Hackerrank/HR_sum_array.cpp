#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n, i;
  scanf("%d", &n);
  int array[n], sum = 0;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &array[i]);
    sum = sum + array[i];
  }
  return sum;
}