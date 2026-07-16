#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size;
    int capacity;
} Cestino;

static Cestino *cestini;
static char *S;

void inizia(int N, int M)
{
    cestini = (Cestino *)malloc(M * sizeof(Cestino));

    for (int i = 0; i < M; i++)
    {
        cestini[i].arr = NULL;
        cestini[i].size = 0;
        cestini[i].capacity = 0;
    }

    cestini[0].arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        cestini[0].arr[i] = i;
    }
    cestini[0].size = N;
    cestini[0].capacity = N;
}

static void push(int b, int x)
{
    if (cestini[b].size == cestini[b].capacity)
    {
        int nuova_capacita = (cestini[b].capacity == 0) ? 4 : cestini[b].capacity * 2;
        cestini[b].arr = (int *)realloc(cestini[b].arr, nuova_capacita * sizeof(int));
        cestini[b].capacity = nuova_capacita;
    }
    cestini[b].arr[cestini[b].size] = x;
    cestini[b].size++;
}

/*
    s a b indica uno spostamento: l'oggetto in cima al cestino
    a è stato spostato in cima al cestino b(è garantito che il cestino contiene almeno un oggetto al momento dello spostamento);
*/
void sposta(int a, int b)
{
    int x = cestini[a].arr[cestini[a].size - 1];
    cestini[a].size--;
    push(b, x);
}

char controlla(int a, int i)
{
    return S[cestini[a].arr[i]];
}

void solve(int t)
{
    int N, M, Q;
    scanf("%d%d%d\n", &N, &M, &Q);
    S = (char *)malloc((N + 1) * sizeof(char));
    scanf("%s\n", S);

    inizia(N, M);

    char *risposta = (char *)malloc((Q + 1) * sizeof(char));
    int n_controlli = 0;

    for (int i = 0; i < Q; i++)
    {
        char type;
        int a, b;
        scanf(" %c%d%d", &type, &a, &b);

        if (type == 's')
        {
            sposta(a, b);
        }
        else
        {
            risposta[n_controlli++] = controlla(a, b);
        }
    }

    risposta[n_controlli] = '\0';

    printf("Case #%d: %s\n", t, risposta);
}

int main()
{
    int T, t;

    // Se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("cestini_input_1.txt", "r", stdin);
    freopen("cestini_output_1.txt", "w", stdout);

    assert(1 == scanf("%d", &T));

    for (t = 1; t <= T; t++)
    {
        solve(t);
    }

    return 0;
}
