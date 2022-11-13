#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// reverte palavras

void reverse_words(char const *strs)
{
    int startword = 0, endword = 0, i, j, k;
    int const siz = strlen(strs);
    // char str[siz];
    // strcpy(str, strs);
    char aux;
    // puts(str);
    for (i = 0; i < siz; i++)
    {
        for (j = i; str[j] != ' ' && j < siz; j++)
        {
            // printf("j: %d w %c", j, str[j]);
        }
        endword = j;
        for (j = endword - 1; j > i; i++, j--)
        {
            aux = str[i];
            str[i] = str[j];
            str[j] = aux;
        }
        i = endword;
    }
    // puts(str);
    return;
}

int main()
{
    reverse_words("The quick brown fox jumps over the lazy dog.");
}