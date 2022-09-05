#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int a[3], b[3], pa=0, pb=0, i;
  for (i = 0; i < 3; i++)
  {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < 3; i++)
  {
    scanf("%d", &b[i]);
  }
  for (i = 0; i < 3; i++)
  {
    if (a[i] > b[i])
    {
      pa++;
    }
    if (a[i] < b[i])
    {
      pb++;
    }
  }
  printf("%d %d", pa, pb);
}