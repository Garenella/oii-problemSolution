#include<stdio.h>

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
    unsigned long n1, n2;
    scanf("%lu %lu", &n1, &n2);
    printf("%lu", n1 + n2);
    return 0;
}
