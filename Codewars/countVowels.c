#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int getCount(const char *inputStr)
{
    int num_vowels = 0, i;
    for (i = 0; inputStr[i] != '\0'; i++)
    {
        if (inputStr[i] == 'a' || inputStr[i] == 'e' || inputStr[i] == 'i' || inputStr[i] == 'o' || inputStr[i] == 'u')
        {
            num_vowels++;
        }
    }
    return num_vowels;
}

int main()
{
    // sample input
    int vogais;
    char input[1001];
    // fgets(input,100,stdin);
    // vogais = getCount(input);
    vogais = getCount("abracadabra");
    printf("%d", vogais);
}