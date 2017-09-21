#include <stdio.h>
#define MAX_SIZE 100000

int vet[MAX_SIZE];

unsigned long findMinProdEvenEven(int); 
unsigned long findMinProdEvenOdd(int);

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
    int N;
    unsigned long min_prod_even_odd, min_prod_even, min_prod;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &vet[i]);
    min_prod_even = findMinProdEvenEven(N);
	min_prod_even_odd = findMinProdEvenOdd(N);
	if(min_prod_even <= min_prod_even_odd)
	 min_prod = min_prod_even;
	else 
     min_prod = min_prod_even_odd;
     
    if(min_prod < 100000001)
        printf("%lu\n", min_prod);
    else 
        printf("-1\n");
	return 0;
}

unsigned long findMinProdEvenEven(int size) 
{
	int min1=10001, min2=10001;
	for(int i = 0; i < size; ++i)
	{
		if( (vet[i] <= min1) && (vet[i]%2==0) ) 
		{
			min2 = min1;
			min1 = vet[i];
		}
		else if( (vet[i] < min2) && (vet[i]%2==0) )
		{
			min2 = vet[i];
        }
    }
	if(min2 < 10001 && min1 < 10001)
		return min1 * min2;
	return 100000001;
}

unsigned long findMinProdEvenOdd(int size) 
{
	int min_even=10001, min_odd=10001;
	for(int i = 0; i < size; ++i)
	{
		if( (vet[i] < min_even) && (vet[i]%2==0) ) 
			min_even = vet[i];
        else if( (vet[i] < min_odd) && (vet[i]%2!=0) )
            min_odd = vet[i];
    }    	
	if(min_odd < 10001 && min_even < 10001)
		return min_even * min_odd;
	return 100000001;
}
