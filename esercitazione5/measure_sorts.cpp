#include <iostream>
#include <vector>
#include <algorithm>    
#include "is_sorted.hpp"       
#include "timecounter.h"
#include "randfiller.h" 

int main(void) {
	
	int n_dimensioni= 12;
	
	
	int k=0; // inizializzo contatore
	//creo vettori per salvare i risultati
		std::vector<double> v_bubble(n_dimensioni) ;
        std::vector<double> v_insertion(n_dimensioni) ;
        std::vector<double> v_selection(n_dimensioni) ;
        std::vector<double> v_sort(n_dimensioni);
		std::vector<double> v_merge(n_dimensioni) ;
        std::vector<double> v_quick(n_dimensioni);
		std::vector<double> v_quick_modificato(n_dimensioni);
    
   
    for (int n = 4; n <= 8192; n = n * 2) {
		
		//creo vettore vec con 100 vettori di dimensione n
        std::vector<std::vector<int>> vec(100, std::vector<int>(n)); 
		
		randfiller rf;
		
		//ogni vettore all'interno lo riempio con numeri casuali
		for (int i=0; i<100; i++){
			rf.fill(vec[i], -10000, 10000); 
		}
		
		//creo 7 copie
        std::vector<std::vector<int>> v1 = vec;
        std::vector<std::vector<int>> v2 = vec;
        std::vector<std::vector<int>> v3 = vec;
        std::vector<std::vector<int>> v4 = vec;
		std::vector<std::vector<int>> v5 = vec;
		std::vector<std::vector<int>> v6 = vec;
		std::vector<std::vector<int>> v7 = vec;

        timecounter tc; 

        //Misura Bubble Sort
        tc.tic();
		//ordino i 100 vettori di dimensione n
		for (int i=0; i<100; i++) {
			bubble_sort(v1[i]);
			}
        double t_bubble = tc.toc();
		v_bubble[k]= t_bubble/100; //calcolo il tempo medio

        //Misura Insertion Sort
        tc.tic();
		//ordino i 100 vettori di dimensione n
		for (int i=0; i<100; i++) {
			insertion_sort(v2[i]);
			}
		double t_insertion = tc.toc();
		v_insertion[k]=t_insertion/100; //calcolo il tempo medio

        //Misura Selection Sort
        tc.tic();
		//ordino i 100 vettori di dimensione n
		for (int i=0; i<100; i++) {
			selection_sort(v3[i]);
			}
        double t_selection = tc.toc();
		v_selection[k]=t_selection/100; //calcolo il tempo medio

        //Misura std::sort
        tc.tic();
		//ordino i 100 vettori di dimensione n
		for (int i=0; i<100; i++) {
			std::sort(v4[i].begin(), v4[i].end());
			}
        double t_std = tc.toc();
		v_sort[k]=t_std/100; //calcolo il tempo medio
		
		//Misura Merge Sort
        tc.tic();
		//ordino i 100 vettori di dimensione n
		for (int i=0; i<100; i++) {
			merge_sort(v5[i], 0, n-1);
			}
        double t_merge = tc.toc();
		v_merge[k]=t_merge/100; //calcolo il tempo medio
		
		
		//Misura Quick Sort
        tc.tic();
		//ordino i 100 vettori di dimensione n
		for (int i=0; i<100; i++) {
			quick_sort(v6[i], 0, n-1);
			}
        double t_quick = tc.toc();
		v_quick[k]=t_quick/100; //calcolo il tempo medio
		
		//Misura Quick Sort Modificato
        tc.tic();
		//ordino i 100 vettori di dimensione n
		for (int i=0; i<100; i++) {
			quick_sort_modificato(v7[i], 0, n-1);
			}
        double t_quick_modificato = tc.toc();
		v_quick_modificato[k]=t_quick_modificato/100; //calcolo il tempo medio
		
		
				

       k++; //incremento contatore per salvare i tempi nel vettore dei tempi 
    }
	
	
	//stampo gli stessi risultati in riga per poi salvarli su Matlab e creare grafico.
	std::cout << "Bubble Sort\n";
	for (int j=0; j<n_dimensioni; j++) {
		std::cout << v_bubble[j] << ", ";
	}
	std::cout <<"\n" << "Insertion Sort\n" ;
	for (int j=0; j<n_dimensioni; j++) {
		std::cout << v_insertion[j] << ", ";
	}
	std::cout <<"\n" << "Selection Sort\n";
	for (int j=0; j<n_dimensioni; j++) {
		std::cout << v_selection[j] << ", ";
	}
	std::cout <<"\n" << "std::sort\n";
	for (int j=0; j<n_dimensioni; j++) {
		std::cout << v_sort[j] << ", ";
	}
	std::cout <<"\n"<< "Merge Sort\n";
	
	for (int j=0; j<n_dimensioni; j++) {
		std::cout << v_merge[j] << ", ";
	}
	std::cout <<"\n Quick Sort\n";
	for (int j=0; j<n_dimensioni; j++) {
		std::cout << v_quick[j] << ", ";
	}
	std::cout <<"\n Quick Sort Modificato\n";
	for (int j=0; j<n_dimensioni; j++) {
		std::cout << v_quick_modificato[j] << ", ";
	}
	
	

    return 0;
}