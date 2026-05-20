#include <iostream>
#include "contenitori.hpp"
#include "grafi.hpp"

int main() {
			
	fifo<int> q2;
	lifo<int> s2;
	unidirected_graph<int> g2;
	
	g2.add_edge(1,2);
	g2.add_edge(1,3);
	g2.add_edge(1,4);
	g2.add_edge(1,6);
	g2.add_edge(2,4);
	g2.add_edge(2,5);
	g2.add_edge(2,7);
	g2.add_edge(3,6);
	g2.add_edge(4,6);
	g2.add_edge(4,7);
	g2.add_edge(5,7);
	g2.add_edge(6,7);
	g2.add_edge(6,8);
	g2.add_edge(7,9);
	g2.add_edge(8,9);
	int node =1;
	
	unidirected_graph<int> bfs = graph_visit(g2, node, q2);
	unidirected_graph<int> dfs = graph_visit(g2, node, s2);
	unidirected_graph<int> dfs_ricorsivo = recursive_dfs(g2, node);
	unidirected_graph<int> dijkstra1 = dijkstra(g2, node);
	
		
	//stampo i grafi da mettere su Graphviz
	
	std::cout << "grafo\n";
    for (const auto& edge : g2.all_edges()){
        std::cout << edge.from() << " -- " << edge.to() << ";\n";
    }
	
	std::cout << "bfs\n";
    for (const auto& edge : bfs.all_edges()){
        std::cout << edge.from() << " -- " << edge.to() << ";\n";
    }
    
    std::cout << "dfs\n";
    for (const auto& edge : dfs.all_edges()){
        std::cout << edge.from() << " -- " << edge.to() << ";\n";
    }    
    
    std::cout << "dfs ricorsivo\n";
    for (const auto& edge : dfs_ricorsivo.all_edges()){
        std::cout << edge.from() << " -- " << edge.to() << ";\n";
    }
	
	std::cout << "dijkstra\n";
    for (const auto& edge : dijkstra1.all_edges()){
        std::cout << edge.from() << " -- " << edge.to() << ";\n";
    }
	
	return 0;
}