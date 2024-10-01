#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Automobile
{
    int costoPerCriceto;
    int capacita;
};

bool confrontaPerCosto(const Automobile &a, const Automobile &b)
{
    return a.costoPerCriceto < b.costoPerCriceto;
}

int main()
{
    int N, M;
    fstream fs("fstream.txt", ios::in | ios::out | ios::trunc);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin >> N >> M;

    std::vector<Automobile> automobili(M);
    for (int i = 0; i < M; ++i)
    {
        std::cin >> automobili[i].costoPerCriceto >> automobili[i].capacita;
    }

    // Ordina le automobili per costo per criceto
    std::sort(automobili.begin(), automobili.end(), confrontaPerCosto);

    int costoTotale = 0;
    int cricetiRimasti = N;
    for (const Automobile &a : automobili)
    {
        int cricetiTrasportabili = std::min(cricetiRimasti, a.capacita);
        costoTotale += cricetiTrasportabili * a.costoPerCriceto;
        cricetiRimasti -= cricetiTrasportabili;
        if (cricetiRimasti == 0)
        {
            break;
        }
    }

    std::cout << costoTotale << std::endl;

    return 0;
}
