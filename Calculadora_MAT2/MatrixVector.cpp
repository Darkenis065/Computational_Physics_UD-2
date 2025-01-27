#include <cstdlib>
#include<iostream>
#include <ostream>
#include<vector>

int main(){
	std::vector<int> v1;
	std::cout <<"Numero de elementos de v1: " << v1.size() << std::endl;
	//std::cout <<"Elementos de v1: "<< v1[3] << std::endl;
	
	//std::vector<int> v2{20,54,36};
	//std::cout <<"Numero de elementos de v2: " << v2.size() << "y el valor es: " << v2 <<std::endl;
	for (int i = 0; i<2 ; i++){
		v1.push_back(i+1);
	}
	for (int i = 0; i<2 ; i++){
		std::cout<<"El elemento v1["<<i<<"] es igual a : " <<v1[i]<<std::endl;
	}

	return 0;
}

