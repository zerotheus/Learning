#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool narcissistic(int value)
{
    int digits = 0, valor, aux, sum = 0;
    for (valor = value; valor > 0; digits++, valor /= 10)
    {
    }
    int arr[digits];
    aux = digits;
    digits--;
    for (valor = value; valor > 0; valor /= 10, digits--)
    {
        arr[digits] = valor % 10;
    }
    for (digits = aux - 1; digits >= 0; digits--)
    {
        sum += pow(arr[digits], aux);
    }
    if (sum == value)
    {
        return true;
    }
    return false;
}

bool narcissistic(int num);

int main()
{
    printf("%d", narcissistic(7) == 1);
    printf("%d", narcissistic(371) == 1);
    printf("%d", narcissistic(122) == 0);
    printf("%d", narcissistic(4887) == 0);
}

/*A Narcissistic Number (or Armstrong Number) is a positive number which is the sum of its own digits, each raised to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10).

For example, take 153 (3 digits), which is narcisstic:

    1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
and 1652 (4 digits), which isn't:

    1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938
The Challenge:

Your code must return true or false (not 'true' and 'false') depending upon whether the given number is a Narcissistic number in base 10. This may be True and False in your language, e.g. PHP.

Error checking for text strings or other invalid inputs is not required, only valid positive non-zero integers will be passed into the function.*/