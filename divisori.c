#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int N) // 1 -> primo ; 0 -> non primo
{
    long long dMax;
    int risp;
    if (N <= 3)
        risp = 1;
    else if (risp = (N % 2) * (N % 3)) // azzera se multiplo di 2 o di 3
    {
        dMax = sqrt(N);
        for (int div = 7; risp && div <= dMax; div += 6)
            risp = ((N % div) || (N % (div - 2)));
    }
    return risp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long x;
    int divisori = 1, dMax;
    scanf("%lld", &x);
    if (x <= 1)
    {
        printf("%d", 1);
    }
    else
    {
        if (isPrime(x)) // numero primo
            printf("%d", 2);
        else
        {
            // fattorizzazione
            dMax = x / 2;
            int *fattori = (int *)calloc(dMax, sizeof(int));
            int j = 0;
            for (int i = 2; x > 1 && i <= x; i++)
            {
                if (x % i == 0)
                {
                    fattori[j]++;
                    x = x / i;
                    i--;
                }
                else
                {
                    j++;
                }
            }

            for (int i = 0; i <= j; i++)
                divisori *= (fattori[i] + 1);
            free(fattori);
            printf("%d", divisori);
        }
    }
}