#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int missingfinder(int list[], int end)
{
    long int pa, inicialterm, missed = 0, i = 0, end;
    end = sizeof(list);
    end = end / 8;
    inicialterm = list[0];
    pa = list[1] - list[0];
    if ((list[end - 1] - list[end - 2]) < pa && pa > 0)
    {
        pa = list[end - 1] - list[end - 2];
    }
    if ((list[end - 1] - list[end - 2]) > pa && pa < 0)
    {
        pa = list[end - 1] - list[end - 2];
    }
    while (list[i] == (inicialterm + pa * i))
    {
        i++;
    }
    missed = list[i - 1] + pa;
    return missed;
    // return list[0];
}

int main()
{
    int arr[] = {1, 3, 5, 9, 11};
    int retorno, bits;
    bits = sizeof(arr);
    bits = bits / 4;
    retorno = missingfinder(arr, bits);
    printf("%d", retorno);
}