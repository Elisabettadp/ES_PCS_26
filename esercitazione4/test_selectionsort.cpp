#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>    
#include "is_sorted.hpp"      
#include "randfiller.h" 

int main() {
    //100 Vettori Casuali 
    for (int i = 0; i < 100; i++) {
 
        int dimensione = 10 + (std::rand() % 491);
        std::vector<int> v(dimensione);

		randfiller rf;

        rf.fill(v, -1000, 1000); 

        selection_sort(v);

        if (is_sorted(v) == false) {
            std::cout << "Errore: Bubble Sort ha fallito su un vettore di interi. \n";
            return EXIT_FAILURE;
        }
    }

    // Vettore di Stringhe
    std::vector<std::string> v_str = {
        "scuola", "libro", "matematica", "algebra", "geometria", 
        "programmazione", "calcolo", "scienza", "matita", "penna"
    };

    selection_sort(v_str);

    if (is_sorted(v_str) == false) {
        std::cout << "Errore: Bubble Sort ha fallito sulle stringhe. \n";
        return EXIT_FAILURE;
    }

    std::cout << "Tutti i test per Bubble Sort completati con successo. \n";
    return EXIT_SUCCESS;
}