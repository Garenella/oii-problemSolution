#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	

	int N, max, min;
    scanf("%d", &N);
    char s[N-1];
    scanf("%s", s);
    min = 1; max = N;
	for (int i = 0; i < N-1; ++i)
	{
		
		if (s[i] == '<')
            printf("%d ", min++);
        else
            printf("%d ", max--);
	}

	printf("%d\n", min);

	return 0;

}
