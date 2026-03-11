#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, const char *argv[]){
	if (argc > 1){
	string filename = argv[1];
	ifstream ifs(filename);
	if ( ifs.is_open() ) {
		string location;
		double temp1;
		double temp2;
		double temp3;
		double temp4;
	while( !ifs.eof() ) {
		ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
		double sum = temp1 + temp2 + temp3 + temp4;
		double mean = sum/4;
		cout << location << " " << mean << "\n";
		}
	}
	else { std::cout << "Il file non si è aperto correttamente\n";
	return 2;}
	}
	else { std::cout << "Non è stato inserito nessun file di testo\n";
	return 1;}
	
	return 0;
}
//g+ -o prog main.cpp
// ./prog testo.txt
// parametro 0 = ./prog
// parametro 1= testo.txt	