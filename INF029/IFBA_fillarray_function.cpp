#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

void get_input(int *returnumbers) // O ponteiro faz a função de retorno pra você//
{
  int numbers[3];
  for (int i = 0; i < 3; i++)
  {
    scanf("%d", &numbers[i]);
    returnumbers[i] = numbers[i];
  }
}

int main()
{
  int n = 3, nums[n];
  get_input(nums);
  for (int i = 0; i < 3; i++)
  {
    printf("%d", nums[i]);
  }
}