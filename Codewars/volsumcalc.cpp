#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// problem statmente in the end of code
long long int raizdebhaskara(int a, int b, long long int c)
{
    long long int r1, r2, delta, deltaoriginal;
    delta = b - 4 * a * c;
    deltaoriginal = delta;
    // printf("%lld", delta);
    delta = pow(delta, 0.5);
    r1 = (b * -1 + delta) / 2 * a;
    r2 = (b * -1 - delta) / 2 * a;
    if (deltaoriginal % delta != 0)
    {
        return -1;
    }
    if (r1 > 0)
    {
        return r1;
    }
    if (r2 > 0)
    {
        return r2;
    }
    return -1;
}

long long findNb(long long m)
{ // search for squared triangular numbers
    int i, vol;
    long long int raizdoNumerotriangular, result = 0;
    raizdoNumerotriangular = pow(m, 0.5);
    if (m % raizdoNumerotriangular != 0)
    {
        return -1;
    }
    raizdoNumerotriangular *= -2;
    result = raizdebhaskara(1, 1, raizdoNumerotriangular);
    return result;
}

int main()
{
    printf("%d", findNb(441) == 6);
}

/*Your task is to construct a building which will be a pile of n cubes. The cube at the bottom will have a volume of n3 n^3n
3
 , the cube above will have volume of (n−1)3 (n-1)^3(n−1)
3
  and so on until the top which will have a volume of 13 1^31
3
 .

You are given the total volume m of the building. Being given m can you find the number n of cubes you will have to build?

The parameter of the function findNb (find_nb, find-nb, findNb, ...) will be an integer m and you have to return the integer n such as n3+(n−1)3+...+13=m n^3 + (n-1)^3 + ... + 1^3 = mn
3
 +(n−1)
3
 +...+1
3
 =m if such a n exists or -1 if there is no such n.

Examples:
findNb(1071225) --> 45

findNb(91716553919377) --> -1*/