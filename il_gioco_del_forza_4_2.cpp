#include <iostream>

#define RIGHE 8
#define COLONNE 10

// Prototipo di funzioni 

int CercaSequenza(int, int, int);

// Struttura dati

int griglia[RIGHE][COLONNE];

// Funzione che stampa la griglia sullo schermo 

void StampaGriglia()
{
    int i, j;

    // scrittura della griglia sullo schermo

    std::cout << "      ";
    for (i = 0; i < COLONNE; i++)
        std::cout << "--";
    std::cout << std::endl;

    for (i = RIGHE; i >= 0; i--)
    {
        std::cout << "Riga: " << i + 1 << "|";

        for (j = 0; j < COLONNE; j++)
            std::cout << griglia[i][j] << " ";
        std::cout << "|" << std::endl;        
    }

    std::cout << "      ";
    for (j = 0; j < COLONNE; j++)
        std::cout << j + 1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

// Funzione che gestisce la lettura della colonna dall'utente 
// Parametri: 
// Giocatore: il numero del giocatore 
// Restituisce un intero 
// numero della colonna (da 1 a COLONNE)

int LetturaColonna(int giocatore)
{
    int colonna_scelta;

    do 
    {
        // Ora si chiede all'utente la colonna 

        std::cout << "Giocatore " << giocatore 
                  << " Scegli una colonna: "; 
        std::cin >> colonna_scelta;

        // Gestione effettiva del gioco, solo se la colonna scelta è valida

        if (colonna_scelta <= 0 || colonna_scelta > COLONNE)
        {
            std::cout << "Hai scelto una colonna sbagliata. Riprova"
                      << std::endl;
            StampaGriglia();
        }
    } while (colonna_scelta <= 0 || colonna_scelta > COLONNE);

    return colonna_scelta;
}

// Funzione che simula la caduta del gettone 
// Parametri:
// Colonna: il numero della colonna (da 1 a COLONNE)
// Restituisce un intero
// valore da 0 a RIGHE - 1: posizione trovata libera
// - 1: riga piena 

int CadutaGettone (int colonna)
{
    int posizione;
    int k;
    
    // Caduta del gettone 

    posizione = 1;

    for (k = RIGHE - 1; k >= 0; k--)
        if (griglia[k][colonna - 1] == 0)
            posizione = k;

    return posizione;
}

// Funzione che esplora la griglia, per calcolare le sequenze 
// Parametri: 
// giocatori: il numero del giocatore restituisce un intero
// 1 : il giocatore ha vinto
// 0 : il giocatore non ha vinto

int EsploraGriglia (int giocatore)
{
    int i, j;

    // ore si verifica che il giocatore abbia fatto 4

    for (i = RIGHE - 1; i >= 0; i--)
    {
        for (j = 0; j < COLONNE; j++)
        {
            if (CercaSequenza(i, j, giocatore) != 0)
                return 1;
        }
    }

    return 0;
}

// Funzione che cerca una sequenza lunga 4 per il giocatore indicato, partendo dalla cella indicata.
// Parametri: 
// riga, colonna: coordinate della cella di partenza 
// giocatore: il numero del giocatore
// Restituisce un intero
// 1 : il giocatore ha vinto
// 0 : il giocatore non ha sequenze che partono dalla cella indicata

int CercaSequenza (int riga, int colonna, int giocatore)
{
    int step, r, c;
    int drighe, dcolonne, delta;
    int conta;

    for (step = 1; step <= 4; step++)
    {
        switch (step)
        {
            case 1: // movimento orizzontale a destra
                drighe = 0;
                dcolonne = 1;
                break;
            case 2: // movimento diagonale a destra in basso
                drighe = -1;
                dcolonne = 1;
                break;
            case 3: // movimento verticale in basso
                drighe = -1;
                dcolonne = 0;
                break;
            case 4: // movimento diagonale a sinistra in basso 
                drighe = -1; 
                dcolonne = -1;
        }   // fine del switch

        r = riga; // uso riga al posto di i
        c = colonna; // uso colonna al posto di j
        conta = 0;

        for (delta = 0; delta < 4; delta++)
        {
            // verifico che le coordinate siano valide 

            if (r < 0 || r >= RIGHE)
                break;
            if (c < 0 || c >= COLONNE)
                break;

            // Ora controllo la casella

            if (griglia[r][c] == giocatore)
                conta++;
            r = r + drighe;
            c = c + dcolonne;
        }
        
        // verifico di avere trovato 4 gettoni
        
        if (conta == 4)
            return 1;
    }   // ciclo su step

    return 0;
}

// Programma Principale 

int main()
{
    int i, j, colonna_scelta;
    int giocatore = 1;
    int fine = 0;
    int piene = 0;
    int posizione;

    // Inizializzo la matrice:
    // 0 = casella vuota
    // 1 - gettone del giocatore 1
    // 2 - gettone del giocatore 2

    for (i = 0; i < RIGHE; i++)
        for (j = 0; j < COLONNE; j++)
            griglia[i][j] = 0;

    do
    {
        StampaGriglia();
        colonna_scelta = LetturaColonna(giocatore);

        // Gestione effettiva del gioco

        posizione = CadutaGettone(colonna_scelta);
        if (posizione < 0)
        {
            std::cout << "La colonna scelta e' piena. Ritenta"
                      << std::endl;
            continue;
        }

        griglia[posizione][colonna_scelta - 1] = giocatore;
        piene++;
        
        if (EsploraGriglia(giocatore))
        {
            StampaGriglia();

            std::cout << "Il giocatore " << giocatore;
            std::cout << " ha vinto !!!" << std::endl;
            fine = 1; 
        }

        // verifico se la griglia e' piena

        if (piene == RIGHE*COLONNE && !fine)
        {
            std::cout << "Stallo: la griglia e' piena." << std::endl;
            fine = 1;
        }

        if (fine)
            continue;

        // gestisco l'alternanza dei turni dei giocatori.

        if (giocatore == 1)
            giocatore = 2;
        else 
            giocatore = 1;
    }   while(!fine);

    return 0;
}

