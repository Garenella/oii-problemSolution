#include <stdio.h>
#include <stdlib.h>

int trova_massimo(int N, int V[])
{
    if (N <= 0)
        return 0;

    int max = V[0];
    int i = 1;

    // Align to 8-wide blocks
    int rem = (N - 1) & 7;
    for (int j = 0; j < rem; ++j)
    {
        int v = V[i++];
        if (v > max)
            max = v;
    }

    // Main unrolled loop (8 at a time)
    for (; i + 7 < N; i += 8)
    {
        int a = V[i];
        int b = V[i + 1];
        int c = V[i + 2];
        int d = V[i + 3];
        int e = V[i + 4];
        int f = V[i + 5];
        int g = V[i + 6];
        int h = V[i + 7];

        if (a > max)
            max = a;
        if (b > max)
            max = b;
        if (c > max)
            max = c;
        if (d > max)
            max = d;
        if (e > max)
            max = e;
        if (f > max)
            max = f;
        if (g > max)
            max = g;
        if (h > max)
            max = h;
    }

    // tail (if any)
    for (; i < N; ++i)
    {
        int v = V[i];
        if (v > max)
            max = v;
    }

    return max;
}