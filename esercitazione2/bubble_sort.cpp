#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	static const int N = 6;
	double v[N] = {1.5, 1.2, 7.3, 3.5, 9.2, 8.4};
	int flag=1;
	while (flag){
		flag = 0;
		for (int j=1; j<N; j++) {
			if (v[j-1]> v[j]) {
				flag=1;
				double temp = v[j-1];
				v[j-1] = v[j];
				v[j] = temp;
			}
		}
	}
	cout << "Vettore ordinato con il Bubble Sort\n";
	for (int i=0; i<N; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
	
	return 0;
}