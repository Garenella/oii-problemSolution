// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int C, F, N, T, n, nf, nc, test;

int contaFilm(int *n, int f)
{
    if (*n <= 0 || f <= 0)
        return 0;
    int count = 0;
    while (*n >= f)
    {
        *n -= f;
        count++;
    }
    return count;
}

int contaCanzoni(int *n, int c)
{
    if (*n <= 0 || c <= 0)
        return 0;
    int count = 0;
    while (*n >= c)
    {
        *n -= c;
        count++;
    }
    return count;
}

int main()
{
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    freopen("download_input_1.txt", "r", stdin);
    freopen("download_output_1.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for (test = 1; test <= T; ++test)
    {
        assert(3 == scanf("%d%d%d", &N, &F, &C));
        nf = contaFilm(&N, F);
        nc = contaCanzoni(&N, C);

        printf("Case #%d: ", test);
        printf("%d %d\n", nf, nc);
    }

    return 0;
}
