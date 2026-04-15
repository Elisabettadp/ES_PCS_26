#pragma once

#include <optional>

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