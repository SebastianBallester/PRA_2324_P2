#include <iostream>
#include <string>
#include <vector>

std::vector<int> ganancia(std::vector<int> peso, std::vector<int> benef, int Mt, int N){

	int T[N + 1][Mt + 1]; //Columnas y filas 
	for(int j = 0; j < Mt + 1; j++)
		T[0][j] = 0; 		//Llenamos la primera fila de ceros, no hay objetos

	for(int i = 1; i < N + 1; i++){
		for(int j = 0; j < Mt + 1; j++){

			if(peso[i-1] > j)
				T[i][j] = T[i - 1][j];
			else
				T[i][j] = std::max(T[i - 1][j], T[i - 1][j - peso[i - 1]] + benef[i - 1]);
		}
	}
	
	int j = Mt;       //Recuperacion de la matriz
	std::vector<int> sol(N);
	for(int i = N; i > 0; i--){
	  if(T[i][j] > T[i - 1][j]){
	    sol[i-1] = 1;
	    j = j - peso[i - 1];
	  }
	  else
	    sol[i-1] = 0;
	}
	return sol;
      
}

int main(){

  std::vector<int> beneficios = {10, 20, 15, 20};
  std::vector<int> peso = {1, 3, 2, 4};
  int Mt = 5;
  int N = 4;
  
  std::vector<int> g = ganancia(peso, beneficios, Mt, N);
	
  for(int i = 0; i < N; i++)
    std::cout << g[i] << " ";
  std::cout << std::endl;

  return 0;
}
			

		
