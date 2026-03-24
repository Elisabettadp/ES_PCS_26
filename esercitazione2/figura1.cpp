#include <iostream>

int main() 
{
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0, 1, 2};
	
	int x = 1; 
	float y = 1.1;
	
	std::cout  << "Valore della variabile x: "<< x << "\n";
		std::cout  << "Valore della variabile y: "<< y << "\n";
	std::cout  << "Indirizzo della variabile x: "<< &x << "\n";
	std::cout  << "Indirizzo della variabile y: "<< &y << "\n\n";
	
	(&y)[1] = 0; //undefined behavior
	std::cout << "Comando a riga 12:\n" << "(&y)[1] = 0; \n\n";
	
	std::cout  << "Valore della variabile x, post modifica: "<< x << "\n";
	std::cout  << "Valore della variabile y: "<< y << "\n";
	std::cout  << "Indirizzo della variabile x: "<< &x << "\n";
	std::cout  << "Indirizzo della variabile y: "<< &y << "\n\n";
	
	for (int i=0; i<4; i++) {
		std::cout  << "Indirizzo dell'elemento ad["<< i<< "]:" << &ad[i] << "\n";
	}
	
	std::cout << "\n";
	
	for (int i=0; i<8; i++) {
		std::cout  << "Indirizzo dell'elemento af["<< i<< "]:" << &af[i] << "\n";
	}
	
	std::cout << "\n";
	
	for (int i=0; i<3; i++) {
		std::cout  << "Indirizzo dell'elemento ai["<< i<< "]:" << &ai[i] << "\n";
	}
	
	std::cout << "\n";
	
	//Il comando a riga 12 tratta l'indirizzo di y (&y) come un vettore e si vuole accedere al secondo elemento,
	//ovvero la casella adiacente a y, dove si trova x. Di conseguenza sto cambiando il valore della variabile x.
	
	//disegnare i vari array. stampando dove sono in memoria.
	//v[0] base
	//v[1] base + 4
	//v[2] base + 8
	//int 4 byte, float 4 byte
	
	return 0;
}