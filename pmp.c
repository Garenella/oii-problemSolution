#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	

    unsigned N, a, b;
    
    unsigned long tmp_prod, min_prod = 100000001;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &a, &b);
        tmp_prod = a * b;
        if (min_prod > tmp_prod && tmp_prod % 2 == 0)
		{
            min_prod = tmp_prod;
		}
	}

    if(min_prod < 100000001)
        printf("%d\n", min_prod);
    else
        printf("-1\n");

	return 0;

}
