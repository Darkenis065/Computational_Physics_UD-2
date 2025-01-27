include <iostream>

const int MAX = 100;
class Matriz{

private:
	int filas, columnas;
	double matriz[MAX][MAX];
public:
	Matriz(int filas, int columnas):filas(filas),columnas(columnas){
	//inicializar con ceros
	for (int i;i<filas;i++){
		for (int j;j<filas;j++){

		matriz[i][j]=0;

		}
	}	
	
	}
	void LeerMatriz(){
	std::cout<<"Ingrese los elementos de A("<<filas<<"x"<<columnas<<"):\n";
	for (int i;i<filas;i++){
	for (int j;j<filas;j++){

			std::cin>>matriz[i][j]=0;

			}
	 
		}
	}
	void LeerMatriz(){
	std::cout<<"Ingrese los elementos de A("<<filas<<"x"<<columnas<<"):\n";
	for (int i;i<filas;i++){
		for (int j;j<filas;j++){

			std::cout<<"A="<<matriz[i][j]<<"\t";

			}
	 
		}
	}
};

class Calculadora(){}

















