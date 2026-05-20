#pragma once
#include <iostream>
#include "grafi.hpp"
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <limits>


template<typename T>
class fifo {
	std::list<T> q;

	
	public:
	//costruttore di default
	fifo() : q() {}
	
	//metodo put()
	void put(T elem) {
		q.push_back(elem);
	}
	
	//metodo get()
	T get(void){
		T first = q.front();
		q.pop_front();
		return first;
	}
	
	//metodo empty()
	bool empty(void) {
		return q.empty();
	}
};

template<typename T>
class lifo {
	std::list<T> s;
	
	public: 
	//costruttore di default
	lifo() : s() {}
	
	//metodo put()
	void put(T elem) {
		s.push_front(elem);
	}
	
	//metodo get()
	T get(void){
		T first = s.front();
		s.pop_front();
		return first;
	}
	
	//metodo empty()
	bool empty(void) {
		return s.empty();
	}

};

template<typename T, typename Contenitore>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& grafo, T nodo, Contenitore& c){
	unidirected_graph<T> result;
	std::map<T, bool> reached;
	for (const auto& n : grafo.all_nodes()) { //auto it = grafo.all_nodes().begin(); it != grafo.all_nodes().end(); it++
		reached[n] = false;
	}
	
	// Controllo se il nodo di partenza esiste, se no restituisco un grafo vuoto
    if (reached.find(nodo) == reached.end()) return result;
	
	reached[nodo] = true;
    c.put(nodo);
	
	
	while (!c.empty()){
		T u = c.get();
		
		for (const auto& v : grafo.neighbors(u)) { //auto it = grafo.neighbors(u).begin(); it != grafo.neighbors(u).end(); it++
			if(!reached[v]){
			reached[v] = true;
			c.put(v);
			result.add_edge(u, v);
			}
		}
	}
	return result;

}

//algoritmo ricorsivo
template<typename T>
void ricorsione(const unidirected_graph<T>& grafo, T u, std::map<T, bool>& reached, unidirected_graph<T>& result) {
    
    reached[u] = true;

    // Esploro i vicini del nodo u
    for (const auto& v : grafo.neighbors(u)) {
        if (!reached[v]) {
            // Se v non è stato visitato, aggiungo l'arco all'albero dei risultati
            result.add_edge(u, v);
            
            // Chiamata ricorsiva
            ricorsione(grafo, v, reached, result);
        }
    }
}


template<typename T>
unidirected_graph<T> recursive_dfs(unidirected_graph<T>& grafo, T nodo){
	unidirected_graph<T> result;
    std::map<T, bool> reached;

    // Inizializzo tutti i nodi come falsi
    for (const auto& n : grafo.all_nodes()) {
        reached[n] = false;
    }

    // Se il nodo sorgente non esiste nel grafo, restituiamo un grafo vuoto
    if (reached.find(nodo) == reached.end()) {
        return result;
    }

    ricorsione(grafo, nodo, reached, result);

    return result;
}



template<typename T>
unidirected_graph<T> dijkstra(const unidirected_graph<T>& grafo, T source) {
    // Grafo con il risultato
    unidirected_graph<T> result;
	
	int INF = std::numeric_limits<int>::max();
    
    // mappe dei predecessori e delle distanze
    std::map<T, T> pred;
    std::map<T, int> dist;
    
    // PQ = Coda di Priorità, greater per avere il minimo in cima
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> PQ;

    // for (i = 0; i < m; i++)
    for (const auto& i : grafo.all_nodes()) {
        dist[i] = INF; // dist[i] = +inf
        // non serve inizializzare pred[i] = -1, basta non inserirlo nella mappa
    }

    // Se il nodo non esiste, esco dall'algoritmo
    if (dist.find(source) == dist.end()) return result;

    // pred[S] = S 
    pred[source] = source; 
    
    // dist[S] = 0
    dist[source] = 0;

    //inizializzo la PQ con le varie coppie
	for (const T& nodo : grafo.all_nodes()){
		PQ.push({dist[nodo], nodo});
	}
    
    //seguo lo pseudocodice visto in aula
    while (!PQ.empty()) {
        
        
        int p = PQ.top().first;  // distanza minore
        T u = PQ.top().second;   // Nodo u con distanza p
        PQ.pop();

        // Se p è maggiore della distanza migliore, lo ignoriamo
        if (p > dist[u]) continue; 

        // esploro nodi vicini
        for (const auto& w : grafo.neighbors(u)) {
            
            //assumo peso=1 per tutti i nodi vicini
            int W_uw = 1; 

            // if (dist[w] > dist[u] + W[u,w])
            if (dist[w] > dist[u] + W_uw) {
                
                // dist[w] = dist[u] + W[u,w]
                dist[w] = dist[u] + W_uw; 
                
                // pred[w] = u
                pred[w] = u;
                
                // aggiorno la PQ
                PQ.push({dist[w], w}); 
            }
        }
    }


    
    // costruisco albero risultati
    for (const auto& nodo : pred) {
        T dopo = nodo.first;
        T prima = nodo.second; //predecessore
        
        // evito self-loop nodo sorgente
        if (dopo != prima) {
            result.add_edge(prima, dopo);
        }
    }

    return result;
}