#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	

	int N, tmp_sum, max_sum = -1, a, b;
	
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &a, &b);
		tmp_sum = a + b;
		if (max_sum < tmp_sum && tmp_sum % 2 == 0)
		{
			max_sum = tmp_sum;
		}
	}

	printf("%d\n", max_sum);

	return 0;

}
