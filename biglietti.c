#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B)
{
    int diff_costi;
    int costo_totale = 0;

    while (N > 0)
    {
        if (N < M)
        {
            if (N * A < B)
                costo_totale += N * A;
            else
                costo_totale += B;
            N = 0;
        }
        else
        {
            diff_costi = (M * A) - B;
            if (diff_costi <= 0)
            {
                costo_totale += A;
                N--;
            }
            else
            {
                costo_totale += B;
                N -= M;
            }
        }
    }

    return costo_totale;
}

int main()
{
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
