#include <stdio.h>

#define PMAX 100000

int soluzioni[PMAX];
int panini[PMAX];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int numeroPanini, max, max_sol = 1;
	scanf("%d", &numeroPanini);
	for (int i = 0; i < numeroPanini; i++)
		scanf("%d", &panini[i]);
	for (int i = numeroPanini - 1; i >= 0; i--)
	{
		max = 0;
		for (int j = numeroPanini - 1; j > i; j--)
		{
			if (panini[i] > panini[j] && soluzioni[j] > max)
				max = soluzioni[j];
		}
		soluzioni[i] = max + 1;
		if (soluzioni[i] > max_sol)
			max_sol = soluzioni[i];
	}
	printf("%d", max_sol);
}