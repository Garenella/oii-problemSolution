#include <stdio.h>
#include <math.h>

int N;

int isPrime(int);

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int div1, DivMax;
	float div2;
	char semiprimo = 'n';

	scanf("%d", &N);

	DivMax = sqrt(N);

	if (N % 2)
	{
		for (int i = 3; semiprimo != 'y' && i <= DivMax; ++i)
		{
			if (isPrime(i))
			{
				div1 = i;
				div2 = ((float)N) / i;
				if (floor(div2) == div2 && isPrime((int)div2))
				{
					semiprimo = 'y';
				}
			}
		}
	}
	if (semiprimo == 'y')
		printf("%d %d\n", div1, (int) div2);
	else
		printf("%d\n", -1);

	return 0;
}

/*===========================================================================
  Verifica se il numero in input è un numero primo
  output:  0    se il numero possiede divisori diversi da 1 e da se` stesso
           >0   se il numero è primo
  Prova prima se il numero è pari o multiplo di 3, poi prova tutti i divisori dispari da 5
  alla radice del numero.
----------------------------------------------------------------------------*/
int isPrime(int num)
{
	int result = 1, Div, DivMax = sqrt(num);

	if (num > 3)
	{
		result = num % 2;

		for (Div = 3; result && Div <= DivMax; Div += 2)
			result = num % Div;
	}

	return result;
}