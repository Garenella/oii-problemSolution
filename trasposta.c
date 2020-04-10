#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void alloca_matrice(int r, int c) ;
void dealloca_matrice(int r) ;
void carica_matrice(int r, int c) ;
void stampa_matrice(int r, int c) ;

int n, m;
long **a;

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	scanf("%d %d", &n, &m);
    alloca_matrice(n, m);
    carica_matrice(n, m);
	stampa_matrice(n, m);
    dealloca_matrice(n);
	return 0;
}

void alloca_matrice(int r, int c) 
{
    a = (long **)malloc(r*sizeof(long *));
    for (int i=0; i<r; i++)
        a[i] = (long *) malloc(c*sizeof(long));
    return;
}

void dealloca_matrice(int r) 
{
    for (int i = 0; i < r; i++){  
       free(a[i]);  
    }     
    free(a);
    return;
}

void carica_matrice(int r, int c) 
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
           scanf("%ld", &a[i][j]);
        }
        
    }
    return;
}

void stampa_matrice(int r, int c) 
{
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
           printf("%ld ", a[i][j]);
        }
        printf("\n");
    }
    return;
}
