/*

Write a program that takes in three arguments,

- a start temperature (in Celsius), 
- an end temperature (in Celsius)
- a step size

Print out a table that goes from the start temperature to the end temperature
(in steps of the step size, you do not actually need to print the final end temperature if the step size does not exactly match)

You should perform input validation:
- do not accept start temperatures less than a lower limit (which your code should specify as a constant)
- higher than an upper limit (which your code should also specify) 

You should not allow a step size greater than the difference in temperatures

*/

#include <iostream>
#include <iomanip>

int main()
{
    // definizione variabili

    double long temperature1, temperature2, temperature3;
    double long conversion1, conversion2, conversion3;
    int precisione = 6;

    // prima temperatura

    std::cout << "| Convertitore da gradi Celsius a Fahrenheit" << std::endl;
    std::cout << "| Inserisci un limite inferiore: ";
    std::cin >> temperature1; 

    // condizione per prima temperatura

    while(temperature1 < 0) 
    {
        std::cout << "| Il valore inserito deve essere maggiore di 0, riprovare: ";
        std::cin >> temperature1;
    }
        
    conversion1 = ((temperature1 * 1.8) + 32);
    
    // seconda temperatura

    std::cout << "| Inserisci un limite maggiore: ";
    std::cin >> temperature2; 

    // condizione per seconda temperatura

    while(temperature2 < 0 && temperature1 > temperature2) 
    {
        std::cout << "| Il valore inserito non e' corretto, (deve essere maggiore della prima temperatura) riprovare:";
        std::cin >> temperature2;
    }
        
    conversion2 = ((temperature2 * 1.8) + 32);

    // terza temperatura

    std::cout << "| Inserisci una temperatura media: ";
    std::cin >> temperature3;
    
    // condizione per terza temperatura

    while(temperature3 > (temperature2 - temperature1)) 
    {
        std::cout << "| Il valore inserito non e' corretto, (deve essere compreso tra la prima e la seconda temperatura) riprovare: ";
        std::cin >> temperature3;
    }
        
    conversion3 = ((temperature3 * 1.8) + 32);

    // Convertitore
    
    std::cout << "| Celsius" << "                 | Fahrenheit" << std::endl;
    std::cout << "| -------" << "                 | ----------" << std::endl;
    
    std::cout << std::fixed << std::setprecision(precisione) << "| " << temperature1; 
    std::cout << "                 " << std::fixed << std::setprecision(precisione) << conversion1 << std::endl;
    
    std::cout << std::fixed << std::setprecision(precisione) << "| " << temperature2; 
    std::cout << "                 " << std::fixed << std::setprecision(precisione) << conversion2 << std::endl;
    
    std::cout << std::fixed << std::setprecision(precisione) << "| " <<temperature3; 
    std::cout << "                 " << std::fixed << std::setprecision(precisione) << conversion3 << std::endl;
    
    return 0;
}