#include <stdio.h>
#define MAX_SIZE 100000

int vet[MAX_SIZE];

int findMaxSumEven(int); 
int findMaxSumOdd(int);

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int N, tmp_sum, max_sum_odd, max_sum_even, max_sum;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &vet[i]);
	max_sum_even = findMaxSumEven(N);
	max_sum_odd = findMaxSumOdd(N);
	if(max_sum_even >= max_sum_odd)
		max_sum = max_sum_even;
	else
		max_sum = max_sum_odd;
	printf("%d\n", max_sum);
	return 0;
}

int findMaxSumEven(int size) 
{
	int max1=-1, max2=-1;
	for(int i = 0; i < size; ++i)
	{
		if( (vet[i] >= max1) && (vet[i]%2==0) ) 
		{
			max2 = max1;
			max1 = vet[i];
		}
		else if( (vet[i] > max2) && (vet[i]%2==0) )
		{
			max2 = vet[i];
		}
	}
	if(max2 != -1 && max1 != -1)
		return max1 + max2;
	return -1;
}

int findMaxSumOdd(int size) 
{
	int max1=-1, max2=-1;
	for(int i = 0; i < size; ++i)
	{
		if( (vet[i] >= max1) && (vet[i]%2!=0) ) 
		{
			max2 = max1;
			max1 = vet[i];
		}
		else if( (vet[i] > max2) && (vet[i]%2!=0) )
		{
			max2 = vet[i];
		}
	}
	if(max2 != -1 && max1 != -1)
		return max1 + max2;
	return -1;
}
