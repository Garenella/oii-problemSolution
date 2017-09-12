#include <stdio.h>
#include <assert.h>

#define MAXN 100000

void ripulisci(int N, char remix[], char testo[]) {
    // Mettete qui il codice della soluzione
    int j=0, fine_parola = 0;
    for (int i=0; i<N; i++) {
        if(remix[i]=='P' && remix[i+1]=='a' && remix[i+2]=='H'){
            //controllo per inserimento spazio tra parole del testo
            if(j>0) 
                fine_parola = 1;
            i+=2;
        }
        else
        if (remix[i]=='T' && remix[i+1]=='u' && remix[i+2]=='N' && remix[i+3]=='Z'){
            if(j>0) 
                fine_parola = 1;
            i+=3;
        }
        else{
            if(fine_parola == 1)
            {
                testo[j] = ' '; //ascii table decimal value 32
                j++;
                fine_parola = 0;
            }
            testo[j]=remix[i];
            j++;
        }
    }
}


char remix[MAXN+1], testo[MAXN+1]; // Maggiore di MAXN per contenere newline

int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(remix == fgets(remix, N + 1, fr));

    ripulisci(N, remix, testo);
    fprintf(fw, "%s\n", testo);
    fclose(fr);
    fclose(fw);
    return 0;
}


