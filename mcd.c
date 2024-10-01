#include <stdio.h>
#include <stdlib.h>

long long calcola_mcd(long long a, long long b)
{
    if (b == 0)
        return a;
    long long tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long a, b, mcd;
    scanf("%lld %lld", &a, &b);
    mcd = calcola_mcd(a, b);
    printf("%lld", mcd);
    return 0;
}