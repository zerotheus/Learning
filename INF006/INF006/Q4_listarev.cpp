#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

int sort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n + 1; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] < key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main()
{
  int i, n = 10;
  int arr[n];
  for (i = 0; i < n; i++)
  {
    printf("digite o elemento %d do vetor\n", i + 1);
    scanf("%d", &arr[i]);
    sort(arr, i);
  }
  for (i = 0; i < n; i++)
  {
    printf("%d", arr[i]);
  }
}
