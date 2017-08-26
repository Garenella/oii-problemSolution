#include <stdio.h>

int findSizeCollatz(int); 

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int N;
	scanf("%d", &N);
	printf("%d\n", findSizeCollatz(N));
	return 0;
}

int findSizeCollatz(int N) 
{
    if( N == 1)
        return 1;
    
    if(N % 2 == 0)
       return 1 + findSizeCollatz(N/2);
    else
       return 1 + findSizeCollatz(N*3+1);
}

