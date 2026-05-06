#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>    
#include "is_sorted.hpp"      
#include "randfiller.h" 

int main() {
	std::vector<int> dimensione(100);
	randfiller rf1;
	rf1.fill(dimensione, 1, 1000);
	
	
    //100 Vettori Casuali 
    for (int i = 0; i < 100; i++) {
 
        int n = dimensione[i];
        std::vector<int> v(n);

		randfiller rf;

        rf.fill(v, -1000, 1000); 

        quick_sort(v, 0, n-1);

        if (is_sorted(v) == false) {
            std::cout << "Errore: Quick Sort ha fallito su un vettore di interi. \n";
            return EXIT_FAILURE;
        }
}
	// Vettore di Stringhe
    std::vector<std::string> v_str = {
        "scuola", "libro", "matematica", "algebra", "geometria", 
        "programmazione", "calcolo", "scienza", "matita", "penna"
    };

    quick_sort(v_str, 0, 9);

    if (is_sorted(v_str) == false) {
        std::cout << "Errore: Quick Sort ha fallito sulle stringhe. \n" ;
        return EXIT_FAILURE;
    }

    std::cout << "Tutti i test per Quick Sort completati con successo. \n" ;
    return EXIT_SUCCESS;
}
