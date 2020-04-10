#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int n, m, size;
    long *a;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	scanf("%d %d", &n, &m);
    size = n * m;
    //alloca matrice
    a = (long *)malloc((n*m)*sizeof(long ));
    //carica valori
    for (int i = 0; i < size; i++)
    {
        scanf("%ld", &a[i]);
    }
    //stampa traposta
    for (int j = 0; j < m; j++)
    {
        for (int i = j; i < size; i+=m)
        {
           printf("%ld ", a[i]);
        }
        printf("\n");
    }
    //dealloca matrice
    free(a);
    return 0;
}
