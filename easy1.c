#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	

	int N, max = INT_MIN, tmp;
	
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &tmp);
		if (max < tmp)
		{
			max = tmp;
		}
	}

	printf("%d\n", max);

	return 0;

}
