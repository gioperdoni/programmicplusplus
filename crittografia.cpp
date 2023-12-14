#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ifstream fin;
    std::ofstream fout;
    int primo;
    char prec;
    char c;

    // Controllo argomenti sulla linea di comando

    if (argc < 3)
    {
        std::cout << "Errore sulla linea di comando." << std::endl;
        std::cout << "Uso: " << argv[0]
                  << " file-testo file-output"
                  << std::endl;

        return 1;  
    }

    // Apertura dei file 

    fin.open(argv[1]);
    if (fin.fail())
    {
        std::cout << "Errore apertura file " << argv[1] << std::endl;
        return 1;
    }

    fout.open(argv[2], std::ios::out);

    if (fout.fail())
    {
        std::cout << "Errore apertura file " << argv[2] << std::endl;
        return 1;
    }

    // Ciclo lettura, codifica e scrittura 
    
    primo = 1; 

    while (fin.get(c))
    {
        if (primo)
        {
            fout << (int)(c - 'A') << " ";
            primo = 0;
        }
        else 
        {
            fout << (int)(c - prec) << " ";
        }
        prec = c;
    }

    // Chiusura dei file 
    fin.close();
    fout.close();

    return 0;
}