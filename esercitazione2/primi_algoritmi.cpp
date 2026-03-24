#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	static const int N = 6;
	double v[N] = {1.5, 1.2, 7.3, 3.5, 9.2, 8.4};
	
	//calcolo del minimo
	double vmin = v[0];
	for (int i=0; i<N; i++) {
		if (v[i]< vmin){
			vmin = v[i];
		}
	}
	
	cout << vmin << " Minimo\n";
	
	//calcolo del massimo
	double vmax = v[0];
	for (int i=0; i<N; i++) {
		if (v[i]> vmax){
			vmax = v[i];
		}
	}

	cout << vmax << " Massimo\n";
	
	//calcolo della media
	double vsum = 0;
	for (int i=0; i<N; i++) {
		vsum = vsum + v[i];
	}
	cout << vsum << " Somma\n";
	
	double mean = vsum/N;
	cout << mean << " Media\n";
	
	
	//calcolo della deviazione standard (come radice della varianza)
	double variance = 0;
	
	for (int i=0; i<N; i++) {
		variance = variance + (v[i] - mean)*(v[i] - mean);
	}
	variance = variance/N;
	
	cout << variance << " Varianza\n";
	
	double dev_standard = sqrt(variance);
	cout << dev_standard << " Deviazione standard\n";
	
	return 0;
}