#include <iostream>

#define RIGHE 8
#define COLONNE 10 

using namespace std;

int main() 
{
    int griglia[RIGHE][COLONNE];

    int colonna_scelta;
    int giocatore = 1;
    int fine = 0;
    int piene = 0;
    int i, j, k, r, c, step;
    int drighe, dcolonne, delta;
    int conta, posizione;

    /*
    
    Inizializzo la matrice: 
    0 = casella vuota
    1 - gettone del giocatore 1
    2 - gettone del giocatore 2

    */

   for (i = 0; i < RIGHE; i++)
        for (j = 0; j < COLONNE; j++)
            griglia[i][j] = 0;
    
    do 
    {
        // scrittura della griglia sullo schermo

        cout << "       ";
        for (i = 0; i < COLONNE; i++)
            cout << "--";
        cout << endl;

        for (i = RIGHE -1; i >= 0; i--)
        {
            cout << "Riga: " << i + 1 << "|";

            for (j = 0; j < COLONNE; j++)
                cout << griglia[i][j] << " ";
            cout << "|" << endl;
        }

        cout << "       ";

        for (i = 0; i < COLONNE; i++)
            cout << "--";
        cout << endl;

        cout << "       ";
        for (j = 0; j < COLONNE; j ++)
            cout << j + 1 << " ";
        cout << endl;
        cout << endl;

        // Ora si richiede all'utente la colonna 

        cout << "Giocatore " << giocatore
             << " Scegli una colonna: ";
        cin >> colonna_scelta; 

        // Gestione effettiva del gioco, solo se la colonna scelta è valida 

        if (colonna_scelta > 0 && colonna_scelta <= COLONNE)
        {
            // Caduta del gettone 

            posizione = -1;

            for (k = RIGHE - 1; k >= 0; k--)
                if (griglia[k][colonna_scelta - 1] == 0)
                    posizione = k;
            
            if (posizione < 0)
            {
                cout << "La colonna scelta e' piena. Ritenta"
                     << endl;
                continue;
            }

            griglia[posizione][colonna_scelta - 1] = giocatore;
            piene++;

            // ora si verifica che il giocatore abbia fatto 4 

            for (i = RIGHE; i >= 0 && !fine; i--)
            {
                for ( j = 0; j < COLONNE && !fine; j++)
                {
                    for (step = 1; step <= 4 && !fine; step++)
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
                            case 4: // movimento diagonale in basso a sinistra
                                drighe = -1;
                                dcolonne = -1;
                        }   // fine del switch

                        r = i; c = j;
                        conta = 0;
                        
                        for (delta = 0; delta < 4;  delta++)
                        {
                            // verifico che le coordinate siano valide

                            if (r < 0 || r >= RIGHE)
                                break;
                            
                            if (c < 0 || c >= COLONNE)
                                break;
                            
                            // ora controllo la casella

                            if (griglia[r][c] == giocatore)
                                conta++;
                            r = r + drighe;
                            c = c + dcolonne;
                        }

                        // verifico di avere trovato 4 gettoni 

                        if (conta == 4)
                        {
                            cout << "Il giocatore " << giocatore; 
                            cout << " ha vinto !!!" << endl;
                            fine = 1;
                        }
                    }   // ciclo su step
                }
            }

            // verifico se la griglia è piena 

            if(piene == RIGHE*COLONNE && !fine)
            {
                cout << "Stallo: la griglia e' piena." << endl;
                fine = 1;
            } 
            if (fine)
                continue;
            
            // gestisco l'alternanza dei turni dei giocatori

            if (giocatore == 1)
                giocatore = 2;
            
            else 
                giocatore = 1;
        } 
        else 
            cout << "Hai scelto una colonna sbagliata. Riprova"
                 << endl;
    } while (!fine);
    
    return 0;
}