#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int digPow(int n, int p)
{
    int dig, ncopy = n, i, sum = 0, res;
    int *num;
    double check, numero = n;
    for (dig = 0; ncopy > 0; ncopy /= 10, dig++)
    {
    };
    // printf("%d\n", dig);
    num = (int *)malloc(dig * sizeof(int));
    for (i = dig - 1, ncopy = n; i >= 0; i--, ncopy /= 10)
    {
        num[i] = ncopy % 10;
    }
    for (i = 0; i < dig; i++)
    {
        sum += pow(num[i], (p + i));
    }
    // printf("%d", sum);
    check = sum / numero;
    res = sum / n;
    if ((check - res) == 0)
    {
        return res;
    }
    return -1;
}

int main()
{
    printf("%d", digPow(89, 1) == 1);
    printf("%d", digPow(92, 1) == -1);
    printf("%d", digPow(46288, 3) == 51);
    printf("%d", digPow(114, 3) == 9);
}

/*Some numbers have funny properties. For example:

89 --> 8¹ + 9² = 89 * 1

695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2

46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

Given a positive integer n written as abcd... (a, b, c, d... being digits) and a positive integer p

we want to find a positive integer k, if it exists, such that the sum of the digits of n taken to the successive powers of p is equal to k * n.
In other words:

Is there an integer k such as : (a ^ p + b ^ (p+1) + c ^(p+2) + d ^ (p+3) + ...) = n * k

If it is the case we will return k, if not return -1.

Note: n and p will always be given as strictly positive integers.*/