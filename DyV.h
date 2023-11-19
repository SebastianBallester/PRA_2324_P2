#include <iostream>
#include <vector>

template <typename T>

int BusquedaBinaria(T x, std::vector<T>& v, int ini, int fin){
	if(ini > fin){
		std::cout << "No se encuentra el elemento por lo tanto es: ";
		return -1;
	}
       	int medio = (ini + fin)/2;

	if(v[medio] == x)
		return medio;
	else if(v[medio] > x)
		return BusquedaBinaria(x, v, ini, medio -1);
	else
		return BusquedaBinaria(x, v, medio +1, fin);
}
template <typename T>

void swap(std::vector<T>& v, int i, int j){

	T aux = v[i];
        v[i] = v[j];
	v[j] = aux;
}

template <typename T>

int Partition(std::vector<T>& v, int ini, int fin){
	
	T x = v[fin];
	int i = ini;
	for(int j = ini; j <= fin - 1; j++){
		if(v[j] <= x){
			swap(v, i, j);
			i++;
		}
	}
	swap(v, i, fin);
	return i;
}

template <typename T>

void QuickSort(std::vector<T>& v, int ini, int fin){

	if(ini < fin){
		int pivot = Partition(v, ini, fin);
		QuickSort(v, ini, pivot -1);
		QuickSort(v,pivot + 1, fin);
	}

}

template <typename T>
void imprimir(std::vector<T> v){
  for(int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << std::endl;
}

template <typename T>
int PartitionMedio(std::vector<T>& v, int ini, int fin){
  int medio = (ini + fin) / 2;
  T x = v[medio];
  int i = ini;
  int j = fin;
  
  while(i <= j){
    while(v[i] < x)
      i++;
    while(v[j] > x)
      j--;
    if(i <= j){
      swap(v,i,j);
      i++;
      j--;
    }
   
  }
  return i;
}

template <typename T>
void QuickSortMedio(std::vector<T>& v, int ini, int fin){

	if(ini < fin){
		int pivot = PartitionMedio(v, ini, fin);
		if(ini < pivot - 1)
		  QuickSortMedio(v, ini, pivot -1);
		if(pivot < fin)
		QuickSortMedio(v,pivot, fin);
	}

}
