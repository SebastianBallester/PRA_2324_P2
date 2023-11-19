#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> Cambio(std::vector<int> v, int m, std::vector<int> sol){

	
	int T[20][20];
	T[0][0] = 0;
	int n = v.size();

	for(int j = 1; j < m+1; j++){
		if(j >= v[0] && T[0][j-v[0]] != -1)
			T[0][j] = 1 + T[0][ j-v[0]];
	}
	for(int i = 1; i < n; i++){
		T[i][0] = 0;
		for(int j = 1; j < m+1; j++){
		if(j < v[i] || T[i][ j - v[i]] == -1)
			T[i][ j] = T[i-1][ j];
		else if(T[i-1][ j] != -1)
			T[i][ j] = std::min(T[i-1][ j], 1 + T[i][ j-v[i]]);
		else
			T[i][ j] = 1 + T[i][j-v[i]];	
		}
	}
	int i = n - 1;
	int j = m;
	while(i >= 0 && j != 0){
		if(i == 0 || T[i][j] != T[i -1][j]){
			sol[i] = sol[i] +1;
			j = j - v[i];
		}
		else
			i = i - 1;
		return sol;
	}				
}

int main(){

	std::vector<int> sol = {0};
	std::vector<int> v = {1, 4, 6};
	sol = Cambio(v, 8, sol);
       for(int i = 0; i < 20; i++)	
		std::cout << sol[i] << " ";
       std::cout << std::endl;
	return 0;
}
