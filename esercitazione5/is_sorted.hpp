#pragma once

#include <optional>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>

template<typename T>

bool is_sorted(const std::vector<T>& vec) { 
	int n = (int)vec.size();
	if (n <= 1) {
		return true; 
		} 
	for (int i = 0; i < n - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            return false; 
        }
    }
    return true;
	}
	
	
//BUBBLE SORT
template <typename T>
void bubble_sort(std::vector<T>& vec) {
    int n = (int)vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (vec[j] < vec[j - 1]) {
                T temp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = temp;
            }
        }
    }
}

//INSERTION SORT
template <typename T>
void insertion_sort(std::vector<T>& vec) {
    int n = (int)vec.size();
    for (int j = 1; j < n; j++) {
        T key = vec[j];
        int i = j - 1;
        
        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            i = i - 1;
        }
        vec[i + 1] = key;
    }
}

//SELECTION SORT
template <typename T>
void selection_sort(std::vector<T>& vec) {
    int n = (int)vec.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        T temp = vec[i];
        vec[i] = vec[min_index];
        vec[min_index] = temp;
    }
}


//FUNZIONE MERGE
template <typename T>
void merge(std::vector<T>& vec, int p, int q, int r) {
	int n1 = q - p + 1; // lunghezza primo segmento
	int n2 = r - q; //lunghezza secondo segmento
	
	std::vector<T> L(n1 + 1);
	std::vector<T> R(n2 + 1);
	
	for (int i=0; i<n1; i++) {
		L[i] = vec[p + i];
	}
	
	for (int j=0; j<n2; j++) {
		R[j] = vec[q + j + 1];
	}
	
	if constexpr (std::is_same<T, std::string>::value) {
		L[n1] = std::string(1000, 'z');
		R[n2] = std::string(1000, 'z');
	}
	else {
		L[n1] = std::numeric_limits<int>::max(); //oppure usare numero grande come 10000000000
		R[n2] = std::numeric_limits<int>::max();
	}
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			vec[k] = L[i];
			i = i + 1;
		}
		else {
			vec[k] = R[j];
			j = j + 1;
		}
	}
}



//MERGE SORT
template <typename T>
void  merge_sort(std::vector<T>& vec, int p, int r) {
	if (p < r) {
		int q = (p + r)/2; //capire
		merge_sort(vec, p,q);
		merge_sort(vec, q + 1, r);
		merge(vec, p, q, r);
	}
}


//PARTITION
template <typename T>
int partition(std::vector<T>& vec, int p, int r) {
	T x = vec[r];
	int i = p-1;
	for (int j=p; j<r; j++) {
		if (vec[j] <= x) {
			i = i+1;
			std::swap(vec[i], vec[j]);
		}
	}
	std::swap(vec[i+1], vec[r]);
	return i+1;
}


//QUICK SORT
template <typename T>
void quick_sort(std::vector<T>& vec, int p, int r) {
	if (p < r) {
		int q = partition(vec, p, r);
		quick_sort(vec, p, q - 1);
		quick_sort(vec, q + 1, r);
	}
}


//QUICK SORT MODIFICATO CON SOGLIA N=50
template <typename T>
void quick_sort_modificato(std::vector<T>& vec, int p, int r) {
	int soglia=50;
	if (r < soglia){
		insertion_sort(vec);
	}
	else if (p < r) {
		int q = partition(vec, p, r);
		quick_sort(vec, p, q - 1);
		quick_sort(vec, q + 1, r);
	}
}
	
