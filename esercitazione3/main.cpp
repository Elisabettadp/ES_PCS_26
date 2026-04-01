#include <iostream>
#include <concepts>
#include "rational.hpp"

int main(void)
{
    rational<int> a(2,4); // Diventa 1/2
    rational<int> b(1,3);
    rational<int> c = a + b;
    
	std::cout << c.num() << "/" << c.den() << "\n";
    std::cout << "Somma normale (1/2 + 1/3): " << c << "\n";
   
    // Test casi speciali 
    rational<int> inf_pos(5, 0);
    rational<int> inf_neg(-3, 0);
    rational<int> zero(0, 5);
	
	
    std::cout << inf_pos.num() << "/" << inf_pos.den() << "\n";
    std::cout << "Costruzione +Inf: " << inf_pos << "\n";
	
	std::cout << inf_neg.num() << "/" << inf_neg.den() << "\n";
    std::cout << "Costruzione -Inf: " << inf_neg << "\n";
    
	
    rational<int> nan_test = inf_pos + inf_neg; // +Inf + (-Inf) = NaN
    std::cout << "+Inf sommato a -Inf: " << nan_test << "\n";
    
    rational<int> div_zero = c / zero; // Numero diviso zero = Inf
	
	std::cout << div_zero.num() << "/" << div_zero.den() << "\n";
    std::cout << "Frazione divisa per zero: " << div_zero << "\n";
   
    return 0;
}

