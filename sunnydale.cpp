#include <bits/stdc++.h>

#define SVINCOLI_MAX 50000
#define GALLERIE_MAX 50000
#define LUMINOSITA_MAX 50000

using namespace std;

int destinazioni[SVINCOLI_MAX + 1];
int luminosita[SVINCOLI_MAX + 1];

int calcolaPercorso(int harmony, int spike)
{
    int percorso = 0;
    int prossimo = 0;
    while (harmony && harmony != spike)
    {
        prossimo = destinazioni[harmony];
        destinazioni[harmony] = 0;
        harmony = prossimo;
        percorso++;
    }
    return harmony != spike ? -1 : percorso;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num_svincoli, num_gallerie, harmony, spike;

    cin >> num_svincoli >> num_gallerie >> harmony >> spike;

    for (int i = 1; i <= num_svincoli; i++)
    {
        destinazioni[i] = 0;
        luminosita[i] = LUMINOSITA_MAX + 1;
    }

    int s1, s2, l;
    for (int i = 1; i <= num_gallerie; i++)
    {
        cin >> s1 >> s2 >> l;

        if (l < luminosita[s1])
        {
            luminosita[s1] = l;
            destinazioni[s1] = s2;
        }
        if (l < luminosita[s2])
        {
            luminosita[s2] = l;
            destinazioni[s2] = s1;
        }
    }

    cout << calcolaPercorso(harmony, spike) << endl;
}
