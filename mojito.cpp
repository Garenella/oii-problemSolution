#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct coordinate { int x,y; };
struct ragazzo {coordinate posizione, lancio;};

int N;
ragazzo giocatori[100];
bool partecipanti[100];
coordinate mojito;

int calcolaDistanza(coordinate, coordinate);
int prossimoGiocatore(coordinate);

int main(int argc, char const *argv[])
{
        int X, Y, num_part = 0;
        fstream in("input.txt",ios::in); //oggetto per gestire l’input
        fstream out("output.txt",ios::out); //oggetto per gestire l’output
        in >> X >> Y;
        in >> mojito.x >> mojito.y;
        in >> N;
        for(int i = 0; i < N; ++i) 
        {
            in >> giocatori[i].posizione.x >> giocatori[i].posizione.y >> giocatori[i].lancio.x >> giocatori[i].lancio.y;
            partecipanti[i] = false;
        }
        int prossima_pos = prossimoGiocatore(mojito);
        while(partecipanti[prossima_pos] != true)
        {
            partecipanti[prossima_pos] = true;
            prossima_pos = prossimoGiocatore(giocatori[prossima_pos].lancio);
            num_part++;
        } 
        out << num_part << endl;
}

int calcolaDistanza(coordinate p1, coordinate p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int prossimoGiocatore(coordinate pos)
{
    int pos_min = -1, dist_tmp, dist_min = 201;

    for (int i = 0; i < N; ++i)
    {
        dist_tmp = calcolaDistanza(pos, giocatori[i].posizione);         
        if (dist_tmp < dist_min)
        {
            dist_min = dist_tmp;
            pos_min = i;
        }
        else if(dist_tmp == dist_min)
        {
            if( 
                giocatori[i].posizione.x < giocatori[pos_min].posizione.x || 
                (giocatori[i].posizione.x == giocatori[pos_min].posizione.x && giocatori[i].posizione.y < giocatori[pos_min].posizione.y)
              )
            {
              pos_min = i;
            }
        }
    }

    return pos_min;
}