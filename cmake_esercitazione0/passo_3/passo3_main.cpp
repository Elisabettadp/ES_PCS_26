#include <iostream>
#include "passo3.h"

int main(void)
{
    double a = f(12.34);
    double b = g(34.56);
    std::cout << "Risultato di f(12.34) + g(34.56): " << a+b << std::endl;
    std::cout << "Passo 3 completato!" << std::endl;
    return 0;
}
