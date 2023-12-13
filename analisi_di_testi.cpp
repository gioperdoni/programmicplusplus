#include <iostream>
#include <string.h>

#define RIGHE 10

using namespace std;

// struttura dati

typedef struct st_stringa
{
    char s[100];

}
STRINGA;

typedef struct st_lettera
{
    int minuscole;
    int maiuscole;
}
LETTERA;

int main() {
    LETTERA lettere[26];
    STRINGA righe[RIGHE];
    int i, j;

    char c;
    int stampa;


    // inizializzazione struttura dati lettere 

    for (i = 0; i < 26; i++)
    {
        lettere[i].minuscole = 0;
        lettere[i].maiuscole = 0;
    }

    // lettura delle dieci righe 
    
    cout << "Inserisci " << RIGHE 
         << " righe di testo" << endl;      

    for (i = 0; i < RIGHE; i++)
    cin.getline(righe[i].s, 80);

    // ispezione delle righe per calcolare la frequenza delle lettere

    for(i = 0; i < RIGHE; i++)
    {
        for(j = 0; j < strlen(righe[i].s); j++)
        {
            c = righe[i].s[j];
            if (c >= 'A' && c <= 'Z')
                lettere[c-'A'].maiuscole++;
            
            if (c >= 'a' && c <= 'z')
                lettere[c-'a'].minuscole++;
        }
    }

    // stampa della frequenza delle lettere 
    
    for (i = 0; i < 26; i++)
    {
        cout << "Lettera: " << ((char)(i+'A'))
             << " Minusc: " << lettere[i].minuscole
             << " Minusc: " << lettere[i].maiuscole
             << " Totale: " 
             << lettere[i].minuscole + lettere[i].maiuscole
             << endl;
    }

    // stampa delle righe che hanno almeno una lettera maiuscola

    for (i = 0; i < RIGHE; i++)
    {
        stampa = 0;

        for (j = 0; j < strlen(righe[i].s); j++)
            if (righe[i].s[j] >= 'A' && righe[i].s[j] <= 'Z')
            stampa = 1;
        if (stampa)
            cout << righe[i].s << endl;
    }

    return 0;
}