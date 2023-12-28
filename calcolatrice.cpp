#include <iostream>

using namespace std;

int main() 
{
    int numero1, numero2, numero3; // dichiarazione variabili 
    bool condizione1(numero1 < 0 || numero1 > 100);

    cout << "| Inserisci tre numeri interi da 1 a 100: " << endl;
    cout << "| Numero 1: ";
    cin >> numero1;
    
    if(numero1 < 0 || numero1 > 100) {
        cout << "| Errore: parametro errato.";
        return 1;
    }

    cout << "| Numero 2: ";
    cin >> numero2;

    if(numero2 < 0 || numero2 > 100 ) {
        cout << "| Errore: parametro errato.";
        return 1;
    }

    cout << "| Numero 3: ";
    cin >> numero3;

    if(numero3 < 0 || numero3 > 100 ) {
        cout << "| Errore: parametro errato.";
        return 1;
    }

    char scelta;

    const char A = 'A';
    const char B = 'B';
    const char C = 'C';
    const char D = 'D';
    const char X = 'X';
    
    int somma = numero1 + numero2 + numero3;
    int prodotto = numero1 * numero2;
    int sottrazione = numero3 - numero1;
    double divisione = double(numero1) / double(numero2);

    do {   
    cout << endl;
    cout << "| Puoi scegliere tra: " << endl;
    cout << "| A - Somma tra primo, secondo e terzo numero" << endl;
    cout << "| B - Prodotto tra primo e secondo numero" << endl;
    cout << "| C - Sottrazione tra terzo e primo numero" << endl;
    cout << "| D - Divisione tra primo e secondo numero" << endl;
    cout << "| X - Uscita dal programma" << endl << endl;
    cout << "| Scelta: ";
    cin >> scelta;

        switch (scelta) {
            case A:
                cout << "| La somma dei tre numeri e': " << somma << endl;
                break;
            case B:
                cout << "| Il prodotto tra il primo e il secondo numero e': " << prodotto << endl;
                break;
            case C:
                cout << "| La differenza tra il terzo e il primo numero e': " << sottrazione << endl;
                break;
            case D:
                cout << "| La divisione tra il primo e il secondo numero e': " << divisione << endl;
                break;
            case X:
                cout << "| Uscita dal programma." << endl;
                return 0;

            default:
                cout << "| Scelta non valida, riprova." << endl;
        }
    } while (scelta != 'A', 'B', 'C', 'D', 'X');

    return 0;    
}