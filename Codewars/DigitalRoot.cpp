#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int digital_root(int n)
{
    int res = 0, copy;
    while (n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    while (res > 9)
    {
        copy = res;
        res = 0;
        while (copy > 0)
        {
            res += copy % 10;
            copy /= 10;
        }
    }
    return res;
}

int main()
{
    printf("%d\n", digital_root(16) == 7);
    printf("%d\n", digital_root(195) == 6);
    printf("%d\n", digital_root(992) == 2);
}

/*Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until
a single-digit number is produced. The input will be a non-negative integer.*/