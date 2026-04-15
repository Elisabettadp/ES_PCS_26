#include <iostream>
#include <vector>
#include <algorithm>    
#include "is_sorted.hpp"       
#include "timecounter.h"
#include "randfiller.h" 

int main(void) {
    
    std::cout << std::scientific << std::setprecision(3);

	std::cout << std::setw(12) << "Dimensione"
          << std::setw(15) << "Bubble"
          << std::setw(15) << "Insertion"
          << std::setw(15) << "Selection"
          << std::setw(15) << "std::sort" << "\n";
		  
	int i=0;
	//creo vettori per salvare i risultati
		std::vector<double> v_bubble(12) ;
        std::vector<double> v_insertion(12) ;
        std::vector<double> v_selection(12) ;
        std::vector<double> v_sort(12);
   
    for (int n = 4; n <= 8192; n = n * 2) {
        
		
        std::vector<int> vettore(n);
		
		randfiller rf;
        rf.fill(vettore, -10000, 10000); 

        //creo 4 copie
        std::vector<int> v1 = vettore;
        std::vector<int> v2 = vettore;
        std::vector<int> v3 = vettore;
        std::vector<int> v4 = vettore;
		

        timecounter tc; 

        //Misura Bubble Sort
        tc.tic();
        bubble_sort(v1);
        double t_bubble = tc.toc();
		v_bubble[i]=t_bubble;

        //Misura Insertion Sort
        tc.tic();
        insertion_sort(v2);
        double t_insertion = tc.toc();
		v_insertion[i]=t_insertion;

        //Misura Selection Sort
        tc.tic();
        selection_sort(v3);
        double t_selection = tc.toc();
		v_selection[i]=t_selection;

        //Misura std::sort
        tc.tic();
        std::sort(v4.begin(), v4.end());
        double t_std = tc.toc();
		v_sort[i]=t_std;

        //Stampo i risultati
        std::cout << std::setw(12) << n
          << std::setw(15) << t_bubble
          << std::setw(15) << t_insertion
          << std::setw(15) << t_selection
          << std::setw(15) << t_std << "\n";
				  
				  
		i++; //incremento contatore per salvare i risultati in un vettore
    }
	
	
	//stampo gli stessi risultati in riga per poi salvarli su Matlab e creare grafico. Non è necessario
	
	for (int j=0; j<12; j++) {
		std::cout << v_bubble[j] << ", ";
	}
	std::cout <<"\n";
	for (int j=0; j<12; j++) {
		std::cout << v_insertion[j] << ", ";
	}
	std::cout <<"\n";
	for (int j=0; j<12; j++) {
		std::cout << v_selection[j] << ", ";
	}
	std::cout <<"\n";
	for (int j=0; j<12; j++) {
		std::cout << v_sort[j] << ", ";
	}
	std::cout <<"\n";

    return 0;
}