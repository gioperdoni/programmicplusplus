#include <iostream>

int main() {
    float numero; // memorizza il numero letto da tastiera
    float min; // serve per calcolare il minimo
    float max; // serve per calcolare il massimo
    float somma = 0; // serve per sommare i numeri
    int n = 0; // serve per contare i numeri letti
    float media; // memorizza la media 
    int primo = 1; // Indica che si sta leggendo il primo numero

    do 
    {
        std::cout << "Inserisci un numero reale "
                  << "(0 per terminare): "; 
        std::cin >> numero;

        if (numero != 0)
        {
            somma += numero;
            n++;
            if (primo)
            {   // nel caso in cui si legge il primo numero
                primo = 0;  // indica che il numero successivo non è più il primo
                min = numero;
                max = numero;
            }
            else 
            {   // nel caso in cui il numero letto non è il primo 
                if (numero < min)
                min = numero; // il numero è il nuovo minimo
                if (numero > max)
                max = numero; // il numero è il nuovo massimo
            }  
        }
    } 
    while (numero != 0);
    
    if (primo)

    std::cout << "La sequenza di numeri e' vuota" << std::endl;

    else 
    {
        media = somma / n;

        std::cout << "Valore minimo: " << min << std::endl;
        std::cout << "Valore massimo: " << max << std::endl;
        std::cout << "Valore medio: " << media << std::endl;
    } 
}