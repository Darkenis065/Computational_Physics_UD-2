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

int Suma(int MatrizA[MAX][MAX],int MatrizB[MAX][MAX], int columnasA,int filasA){
	int MatrizC[MAX][MAX];
	for (int i = 0;i<columnasA;i++){
		for (int j = 0;j<filasA;j++)
			MatrizC[i][j] = MatrizA[i][j] + MatrizB[i][j];
	}
	return MatrizC[MAX][MAX];
}

int main(){
	int filasA, columnasA, filasB, columnasB, filasC, columnasC;
	int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
	std::cout<<"Introduzca el numero de filas y columnas de la matriz A"<<std::endl;
	std::cin>> filasA >> columnasA;
	leerMatriz(A,filasA,columnasA);
	MostrarMatriz(A,filasA,columnasA);
	std::cout<<"Introduzca el numero de filas y columnas de la matriz B"<<std::endl;
	std::cin>> filasB >> columnasB;
	leerMatriz(B,filasB,columnasB);
	MostrarMatriz(B,filasB,columnasB);
	C = Suma(A,B,columnasA,filasA);
	MostrarMatriz(C,filasA,columnasA);
return 0;
}
