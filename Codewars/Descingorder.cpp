#include <cinttypes>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int particao(int esquerda, int direita, uint64_t arr[])
{
    uint64_t pivot = arr[direita];
    int i = esquerda - 1, j;
    uint64_t aux;
    for (j = esquerda; j < direita; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
    }
    arr[direita] = arr[i + 1];
    arr[i + 1] = pivot;
    return i + 1;
}

void quicksort(int esquerda, int direita, uint64_t arr[])
{
    int pivot;
    if (esquerda < direita)
    {
        pivot = particao(esquerda, direita, arr);
        quicksort(esquerda, pivot - 1, arr);
        quicksort(pivot + 1, direita, arr);
    }
}

uint64_t descendingOrder(uint64_t a)
{
    uint64_t b;
    int c = 0, i = 0, cont = 0;
    b = a;
    if (b == 0)
    {
        return a;
    }
    while (b > 0)
    {
        b = b / 10;
        c++;
    }
    if (c == 1)
    {
        return a;
    }
    uint64_t arr[c], result = 0;
    b = a;
    i = c;
    while (b > 0)
    {
        c--;
        arr[c] = b % 10;
        b = b / 10;
    }
    quicksort(0, i - 1, arr);
    for (c = i - 1; c >= 0; c--)
    {
        // printf("%ld", arr[c]);
        if (arr[c] == 0)
        {
            cont++;
        }
        if (arr[c] != 0) // pow has return of double, so USE static cast
            result += arr[c] * static_cast<uint64_t>(pow(10, c));
        if (cont > 0 && result % 10 != 0)
        {
            result = result - result % 10;
        }
        printf("result %ld %ld arr[c]\n", result, arr[c]);
    }
    printf("\n%ld c %ld", result, a);
    // printf("\n");
    return result;
}
int main()
{
    printf("%d\n", (descendingOrder(0) == (0)));
    printf("%d\n", (descendingOrder(1) == (1)));
    printf("%d\n", (descendingOrder(15) == (51)));
    printf("%d\n", (descendingOrder(1021) == (2110)));
    printf("%d\n", (descendingOrder(123456789) == (987654321)));
}