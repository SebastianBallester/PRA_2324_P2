#include <iostream>
#include "DyV.h"


int main(){
	std::cout << std::boolalpha;
	std::vector<int> a = {1,5,9,10,4};
	std::vector<double> b = {1.3, 1.2, 40.1, 11.6, 12.8};
	std::vector<char> c = {'y','b','e','d','c'};

	QuickSortMedio(a, 0, 4);
	QuickSortMedio(b, 0, 4);
	QuickSortMedio(c, 0, 4);

	std::cout << BusquedaBinaria(5, a, 0, 4) << std::endl;
	std::cout << BusquedaBinaria(4.2, b, 0, 4) << std::endl;
	std::cout << BusquedaBinaria('e', c, 0, 4) << std::endl;
	

	
	imprimir(a);
	imprimir(b);
	imprimir(c);

	

	return 0;
}
