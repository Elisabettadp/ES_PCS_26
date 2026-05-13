#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


template<typename T>
class unidirected_edge {
	T nodo1;
	T nodo2;
	
//funzione controllo nodo1<nodo2
	
public: 
	// costruttore
	unidirected_edge(T n1, T n2) {
		// controllo ordine nodi
		if (n1 < n2) {
			nodo1 = n1;
			nodo2 = n2;
		} else {
			nodo1 = n2;
			nodo2 = n1;
		}
	}
	
	//restituisco valori dei due nodi
	T from() const {return nodo1;}
	T to() const {return nodo2;}
	
	bool operator<(const unidirected_edge<T>& other) const {
		//unidirected_edge<T> ed = *this; non è necessario usare ed.nodo1 e ed.nodo2
		if (nodo1 < other.nodo1){
			return true;
		}
		if (nodo1 > other.nodo1) {
			return false;
		}
		return nodo2 < other.nodo2;
	}
	
	
	bool operator==(const unidirected_edge& other) const {
		//unidirected_edge ed = *this;
	if (nodo1 == other.nodo1 && nodo2 == other.nodo2) {
		return true;}
	else {
		return false;}
	
	}
	
	
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& ed) {
		os << "(" << ed.from() << ", " << ed.to() << ")";
return os;
}



template<typename T>
class unidirected_graph {
	
	std::map<T, std::set<T>> adj_list;
	std::vector<unidirected_edge<T>> edges;
	std::set<T> nodes;
	
	
	public:
	//costruttore di default
	unidirected_graph() = default;
	
	
	//costruttore di copia
	unidirected_graph(const unidirected_graph& other) = default;
	
	//metodi
	
	//trovo l'insieme dei nodi vicini dato un nodo
	std::set<T> neighbors(T nodo) const {
		//cerco il nodo nella mappa
		auto it = adj_list.find(nodo);
		if (it == adj_list.end()){
			return std::set<T>(); //se il nodo non c'è restituisco insieme vuoto
		}
		return it->second; 
	}
	
		
	
	//aggiungo un arco
	void add_edge(T n1, T n2) {
		unidirected_edge<T> new_edge(n1, n2);
		
		//CHIEDI SE è DA FARE
		//controllo se l'arco è già presente nel grafo
		auto it = std::find(edges.begin(), edges.end(), new_edge);
		
		if (it == edges.end()) {
			edges.push_back(new_edge);
			
			//sto lavorando con i set, quindi se questi collegamenti esistono già il set gli ignora, lo stesso con i nodi
			// Aggiorno la lista di adiacenza
            adj_list[n1].insert(n2);
            adj_list[n2].insert(n1);
			
			// Aggiungo i nodi all'insieme dei nodi
            nodes.insert(n1);
            nodes.insert(n2);
		}
		
	}
	
	
	//restituisco tutti gli archi
	std::vector<unidirected_edge<T>> all_edges() const {
		return edges;
	}
	
	//restituisco tutti i nodi
	std::set<T> all_nodes() const {
		return nodes;
	}
	
	//dato un arco restituisco l'indice
	int edge_number(const unidirected_edge<T>& ed) const {
		auto it = std::find(edges.begin(), edges.end(), ed);
		if (it != edges.end()) {
			return std::distance(edges.begin(), it); //distanza dall'inzio a it, ovvero indice del vettore
		}
		return -1; //se l'arco non esiste
	}
	
	//dato un indice restituisco l'arco
	unidirected_edge<T> edge_at(int index) const {
		if (index >= 0 && index < (int)edges.size()) {
            return edges[index];
        }
		return unidirected_edge<T>(T{}, T{}); //se l'indice è fuori dal vettore restituisco un arco vuoto
		
		//throw std::out_of_range("Invalid edge index"); altrimenti potrei lanciare errore
	}
	
	unidirected_graph operator-(const unidirected_graph& other) const{
		unidirected_graph result;
		
		std::vector<unidirected_edge<T>> edges_other = other.all_edges();
		
		for (int i=0; i<(int)edges.size() ;i++) {
			auto it = std::find(edges_other.begin(), edges_other.end(), edges[i]);
			if (it == edges_other.end()){
				result.add_edge(edges[i].from(), edges[i].to());
			}
		}
		return result;
		}
};