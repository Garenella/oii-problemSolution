#include<stdio.h>

unsigned long getFibonacciPosition(int pos);

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
    int  p;
    unsigned long fibNumber;
    scanf("%d", &p);
    fibNumber = getFibonacciPosition(p);
    printf("%lu", fibNumber);
    return 0;
}

unsigned long getFibonacciPosition(int pos)
{
    if(pos == 0) return 0;
    if (pos == 1 || pos == 2) return 1;
    int cont = 3;
    unsigned long N = 1, n = 1, somma=0; 
    while (cont <= pos)
    {
        somma = N + n;
        n=N;
        N = somma;
        cont++;
    }
    return somma;
}