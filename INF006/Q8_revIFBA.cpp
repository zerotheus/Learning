#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
/*Criar programa que leia dados de 20 elementos inteiros. imprimir o maior
e o menor, sem ordenar, o percentual de números pares e a media dos
elementos do vetor.*/
int main()
{
  int n = 20, arr[n], maior, menor, i;
  float media, par=0;
  for (i = 0; i < n; i++)
  {
    
    printf("digite um numero\n");
    scanf("%d", & arr[i]);
    media=media+arr[i];
    if(i==0){
      maior=arr[i];
      menor=arr[i];
    }
    if (arr[i]%2==0)
    {
      par++;
    }
    if (arr[i]>maior)
    {
      maior=arr[i];
    }
    if (arr[i]<menor)
    {
      menor=arr[i];
    }
  }
 media=media/n;
 par=par/n;
 par=par*100;
 printf("maior :%d menor: %d\nPares: %1.f%\n media: %1.f", maior, menor, par, media); 
}