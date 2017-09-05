#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int A, B, H, num_giorni = 0;
    scanf("%d %d %d", &A, &B, &H);
    H = H-A;
    A = A-B;
    for(int i = 0; i < H; i+=A)
    {
        num_giorni++;
    }   
	printf("%d\n", ++num_giorni);
	return 0;
}
