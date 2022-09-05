#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int n=5, i, max, min;
  long int arr[n], sum=0, maxsum=0, minsum=0;
  for (i = 0; i < n; i++)
  {
    scanf("%ld", &arr[i]);
    if (max < arr[i] || i == 0)
    {
      max = arr[i];
    }
    if (min > arr[i] || i == 0)
    {
      min = arr[i];
    }
    sum += arr[i];
  }
  maxsum = sum - min;
  minsum = sum - max;

  printf("%ld %ld", minsum, maxsum);
}