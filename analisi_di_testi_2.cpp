#include <iostream>
#include <string.h>

#define RIGHE 10

// struttura dati

typedef struct st_stringa
{
    char s[100];
} STRINGA;

typedef struct st_lettera
{
    int minuscole;
    int maiuscole;
} LETTERA;

LETTERA lettere[26];
STRINGA righe[RIGHE];

int testo_letto = 0;

// Funzione che gestisce il menu
// Parametri: nessuno
// Restituisce un intero
// numero dell'opzione valida scelta

int Menu()
{
    int scelta;

    do 
    {
        std::cout << std::endl;
        std::cout << "Scegli un'operazione" << std::endl;
        std::cout << "1 - Lettura del testo" << std::endl;
        std::cout << "2 - Analisi frequenza lettere" << std::endl;
        std::cout << "3 - Stampa righe con maiuscole" << std::endl;
        std::cout << "4 - Stampa testo intero" << std::endl;
        std::cout << "5 - Fine operazioni" << std::endl;

        std::cin >> scelta;

        if (scelta < 1 || scelta > 5)
            std::cout << "Hai scelto un'opzione non valida" << std::endl;
    } while (scelta < 1 || scelta > 5);

    return scelta;
}

// Funzione che legge il testo da tastiera 
// Parametri: nessuno 
// Valore restituito: nessuno

void LetturaTesto()
{
    int i;

    // lettura delle dieci righe 

    std::cout << "Inserisci " << RIGHE 
              << " righe di testo" << std::endl;
    
    for (i = 0; i < RIGHE; i++)
        std::cin.getline(righe[i].s, 80);
    
    // indica al programma che il testo e' stato letto

    testo_letto = 1;
}

// Funzione che stampa le righe con lettere maiuscole 
// Parametri: nessuno
// Valore restituito: nessuno 

void StampaRigheMaiuscole()
{
    int i, j;
    int stampa;

    if (!testo_letto)
    {
        std::cout << "Non e' stato letto un testo" << std::endl;
        return;
    }

    // Stampa delle righe che hanno almeno una lettera maiuscola

    for (i = 0; i < RIGHE; i++)
    {
        stampa = 0;

        for (j = 0; j < strlen(righe[i].s); j++)
            if (righe[i].s[j] >= 'A' && 
                righe[i].s[j] <= 'Z')
                stampa = 1;
        
        if (stampa)
        std::cout << righe[i].s << std::endl;
    }
}

// Funzione che analizza il testo per contare la frequenza delle lettere; stampa anche le frequenze sullo schermo
// Parametri: nessuno 
// Valore restituito: nessuno 

void AnalisiTesto()
{
    char c;
    int i, j;

    if (!testo_letto)
    {
        std::cout << "Non e' stato letto un testo" << std::endl;
        return;
    }

    // ispezione delle righe per calcolare la frequenza delle lettere 

    for (i = 0; i <  RIGHE; i++)
    {
        for (j = 0; j < strlen(righe[i].s); j++)
        {
            c = righe[i].s[j];

            if (c >= 'A' && c <= 'Z')
                lettere[c -'A'].maiuscole++;

            if (c >= 'a' && c <= 'z')
                lettere[c -'a'].minuscole++;
        }
    }

    // Stampa della frequenza delle lettere 

    for (i = 0; i < 26; i++)
    {
        std::cout << "Lettera: " << ((char)(i + 'A'))
                  << " Minusc: " << lettere[i].minuscole
                  << " Maiusc: " << lettere[i].maiuscole
                  << "Totale : "
                  << lettere[i].minuscole + lettere[i].maiuscole
                  << std::endl;
    }
}

// Funzione che stampa il testo sullo schermo
// Parametri: nessuno 
// Valore restituito: nessuno 

void StampaTesto()
{
    int i, j;

    if (!testo_letto)
    {
        std::cout << "Non e' stato letto un testo" << std::endl;
        return;
    }

    for (i = 0; i < RIGHE; i++)
    {
        std::cout << righe[i].s << std::endl;
    }
}

int main()
{
    int scelta;
    int i;

    // inizzializzazione struttura dati lettere

    for (i = 0; i < 26; i++)
    {
        lettere[i].minuscole = 0;
        lettere[i].maiuscole = 0;
    }

    do
    {
        scelta = Menu();
        switch(scelta)
        {
            case 1: // lettura testo
                LetturaTesto();
                break;
            case 2: // analisi frequenza lettere
                AnalisiTesto();
                break;
            case 3: // stampa righe con maiuscole
                StampaRigheMaiuscole();
                break;
            case 4: // stampa 
                StampaTesto();
                break;
            case 5: // uscita
            default:
                break;
        }
    } while (scelta != 5);

    return 0;
}