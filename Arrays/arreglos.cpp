#include<iostream>

const int MAX=100;

void leerMatriz(int matriz[MAX][MAX], int filas, int columnas){
	std::cout<<"Introduzca los elementos de la matriz ("<<filas<<"x"<<columnas<<")"<<std::endl;
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
		std::cout<<"Elemento A["<<i<<"]["<<j<<"]=";
		std::cin>>matriz[i][j];
		}
	}
}

void MostrarMatriz(int matriz[MAX][MAX], int filas, int columnas){
	std::cout<<"La matriz es: \n";
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
		std::cout<<matriz[i][j]<<"\t";
		}
	std::cout<<std::endl;
	}
}

int main(){
	int filasA, columnasA;
	int A[MAX][MAX];
std::cout<<"Introduzca el numero de filas y columnas de la matriz A"<<std::endl;
std::cin>> filasA >> columnasA;
leerMatriz(A,filasA,columnasA);
MostrarMatriz(A,filasA,columnasA);
}
