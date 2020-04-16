#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N;
    scanf("%d", &N);
    int v[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &v[i]);
    qsort(v, N, sizeof(int), compare);
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);
    return 0;
}