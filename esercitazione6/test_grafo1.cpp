#include <iostream>
#include <vector>
#include <cstdlib>
#include "grafi.hpp"    

int main() {
	//Verifica l'invarianza dell'arco
    unidirected_edge<int> e1(10, 5);
    std::cout << "Test Arco (10, 5): " << e1 << "\n";
    if (e1.from() != 5){
		return 	EXIT_FAILURE;
	}
    
    //Costruzione del grafo
    unidirected_graph<int> g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(3, 1);
	g1.add_edge(1, 4);

    
    // Controllo il numero di nodi e archi
    if(g1.all_nodes().size() != 4){
		return 	EXIT_FAILURE;
	}
    if(g1.all_edges().size() != 4){
		return 	EXIT_FAILURE;}
		

    //Neighbors
    // Il nodo 2 deve avere come vicini 1 e 3
    std::set<int> v2 = g1.neighbors(2);
    if(v2.size() != 2){return EXIT_FAILURE;}
    if(v2.count(1) != 1){return EXIT_FAILURE;}
    if(v2.count(3) != 1){return EXIT_FAILURE;}
    std::cout << "Test vicini per il nodo 2 superato.\n";

	//ctrl k, e ctrl q
    // Numerazione archi
    // Verifichiamo la coerenza tra edge_number e edge_at
    unidirected_edge<int> secondo_arco = g1.edge_at(1);
    int indice = g1.edge_number(secondo_arco);
    if(indice != 1){return EXIT_FAILURE;}
    std::cout << "Test indicizzazione arco superato: " << secondo_arco << " e' l'indice 1.\n";

    // Differenza tra grafi (operator-) 
    unidirected_graph<int> g2;
    g2.add_edge(1, 2); // Arco comune a g1
    
    // g3 = g1 - g2 conterrà gli archi di g1 non presenti in g2
    unidirected_graph<int> g3 = g1 - g2;
    
    if(g3.all_edges().size() != 3){return EXIT_FAILURE;} // Rimangono (2,3) e (3,1) e (1,4)
    if(g3.edge_number(unidirected_edge<int>(1, 2)) != -1){return EXIT_FAILURE;} // L'arco (1,2) non deve esserci
    std::cout << "Test operatore differenza superato.\n";

    // Costruttore di copia
    unidirected_graph<int> g_copy(g1);
    if(g_copy.all_nodes().size() != g1.all_nodes().size()){return EXIT_FAILURE;}
    if(g_copy.all_edges().size() != g1.all_edges().size()){return EXIT_FAILURE;}
    std::cout << "Test costruttore di copia superato." << std::endl;

    std::cout << "\n tutti i test sono stati superati con successo\n";
	
	
	return EXIT_SUCCESS;
}