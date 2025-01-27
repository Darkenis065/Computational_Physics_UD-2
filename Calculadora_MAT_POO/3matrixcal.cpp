#include<iostream>
#include<cmath>
#include<fstream>

const int MAX = 100;

// Clase Matriz
class Matriz {
public:
    int filas, columnas;
    double A[MAX][MAX];

    Matriz(int f, int c) : filas(f), columnas(c) {}

    void leerMatriz() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                std::cout << "Elemento A[" << i << "][" << j << "]: ";
                std::cin >> A[i][j];
            }
        }
    }

    virtual void calcular(const Matriz& B, Matriz& resultado) = 0; // Método virtual puro
};

// Clase para la suma
class MatrizSuma : public Matriz {
public:
    MatrizSuma(int f, int c) : Matriz(f, c) {}

    void calcular(const Matriz& B, Matriz& resultado) override {
        if (filas != B.filas || columnas != B.columnas) {
            std::cerr << "Error: Las matrices deben tener las mismas dimensiones para la suma.\n";
            return;
        }
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.A[i][j] = A[i][j] + B.A[i][j];
            }
        }
    }
};

// Clase para la resta
class MatrizResta : public Matriz {
public:
    MatrizResta(int f, int c) : Matriz(f, c) {}

    void calcular(const Matriz& B, Matriz& resultado) override {
        if (filas != B.filas || columnas != B.columnas) {
            std::cerr << "Error: Las matrices deben tener las mismas dimensiones para la resta.\n";
            return;
        }
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.A[i][j] = A[i][j] - B.A[i][j];
            }
        }
    }
};

// Clase para la multiplicación
class MatrizMultiplicacion : public Matriz {
public:
    MatrizMultiplicacion(int f, int c) : Matriz(f, c) {}

    void calcular(const Matriz& B, Matriz& resultado) override {
        if (columnas != B.filas) {
            std::cerr << "Error: El número de columnas de la matriz A debe ser igual al número de filas de la matriz B para la multiplicación.\n";
            return;
        }
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < B.columnas; j++) {
                resultado.A[i][j] = 0;
                for (int k = 0; k < columnas; k++) {
                    resultado.A[i][j] += A[i][k] * B.A[k][j];
                }
            }
        }
    }
};
class MatrizHadmard: public Matriz{
	public:
		MatrizHadmard(int f, int c): Matriz(f, c){}

		void calcular(const Matriz& B, Matriz& resultado) override{
		if (columnas != B.columnas){
		        std::cerr << "Error: El número de columnas de la matriz A debe ser igual al número de columnas de la matriz B para la multiplicación.\n";
			return;
		}

		else if (filas != B.filas){
		        std::cerr << "Error: El número de filas de la matriz A debe ser igual al número de filas de la matriz B para la multiplicación.\n";
			return;		
		}
	        for (int i = 0; i < filas; i++) {
           	    for (int j = 0; j < B.columnas; j++) {
                	resultado.A[i][j] = 0;
                	resultado.A[i][j] += A[i][j] * B.A[i][j];
                		
            		}
        	}
	}
};
// Clase para el determinante
class MatrizDeterminante : public Matriz {
public:
    MatrizDeterminante(int f, int c) : Matriz(f, c) {}

    double calcularDeterminante() {
        if (filas != columnas) {
            std::cerr << "Error: El determinante solo se puede calcular para matrices cuadradas.\n";
            return 0;
        }

        double det = 1;
        for (int i = 0; i < filas; i++) {
            if (A[i][i] == 0) {
                std::cerr << "Error: No se puede calcular el determinante con un pivote nulo.\n";
                return 0;
            }

            for (int j = i + 1; j < filas; j++) {
                double factor = A[j][i] / A[i][i];
                for (int k = 0; k < columnas; k++) {
                    A[j][k] -= factor * A[i][k];
                }
            }
        }

        for (int i = 0; i < filas; i++) {
            det *= A[i][i];
        }

        return det;
    }

    void calcular(const Matriz& B, Matriz& resultado) override {
        double det = calcularDeterminante();
        std::cout << "El determinante es igual a " << det << std::endl;
    }
};

class Matriztranspue : public Matriz {
public:
    Matriztranspue(int f, int c) : Matriz(f, c) {}

void calcular(const Matriz& B, Matriz& resultado) override {
        if (filas != B.columnas || columnas != B.filas) {
            std::cerr << "Error: Las dimensiones de la matriz deben coincidir para calcular la transpuesta.\n";
            return;
        }
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.A[j][i] = A[i][j];
            }
        }
    }
};
class MatrizInversaCofactores : public Matriz {
public:
    MatrizInversaCofactores(int f, int c) : Matriz(f, c) {}

    double calcularDeterminante(double matriz[MAX][MAX], int n) {
        if (n == 1) {
            return matriz[0][0];
        }

        if (n == 2) {
            return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
        }

        double det = 0;
        double submatriz[MAX][MAX];

        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x) continue;
                    submatriz[subi][subj] = matriz[i][j];
                    subj++;
                }
                subi++;
            }
            det += (x % 2 == 0 ? 1 : -1) * matriz[0][x] * calcularDeterminante(submatriz, n - 1);
        }

        return det;
    }

    void calcular(const Matriz& B, Matriz& resultado) override {
        if (filas != columnas) {
            std::cerr << "Error: La inversa solo se puede calcular para matrices cuadradas.\n";
            return;
        }

        double det = calcularDeterminante(A, filas);
        if (fabs(det) < 1e-9) {
            std::cerr << "Error: La matriz no es invertible.\n";
            return;
        }

        double cofactores[MAX][MAX];

        // Calcular la matriz de cofactores
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                double submatriz[MAX][MAX];
                int subi = 0;

                for (int x = 0; x < filas; x++) {
                    if (x == i) continue;
                    int subj = 0;
                    for (int y = 0; y < columnas; y++) {
                        if (y == j) continue;
                        submatriz[subi][subj] = A[x][y];
                        subj++;
                    }
                    subi++;
                }

                cofactores[i][j] = (pow(-1, i + j) * calcularDeterminante(submatriz, filas - 1));
            }
        }

        // Calcular la adjunta (traspuesta de la matriz de cofactores)
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.A[i][j] = cofactores[j][i] / det;
            }
        }
    }
};


// Función para mostrar la matriz
void mostrarMatriz(const Matriz& matriz) {
    for (int i = 0; i < matriz.filas; i++) {
        for (int j = 0; j < matriz.columnas; j++) {
            std::cout << matriz.A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int filasA, columnasA, filasB = 0, columnasB = 0;
    char operacion;

    std::cout << "Introduce el número de filas para la matriz A: ";
    std::cin >> filasA;
    std::cout << "Introduce el número de columnas para la matriz A: ";
    std::cin >> columnasA;

    std::cout << "Introduce la operación \n 1, Suma:\n 2, Resta:\n 3, Multiplicación:\n  4, Producto Hadmard:\n 5, Determinante:\n 6, Transpuesta:\n 7, Inversa:\n ";
    std::cin >> operacion;

    Matriz* matrizA;
    Matriz* matrizB = nullptr; // Solo se necesita para operaciones 1, 2 y 3
    Matriz* resultado = nullptr; 

//realizo el menu
    if (operacion == '1') {
        matrizA = new MatrizSuma(filasA, columnasA);
        std::cout << "Introduce el número de filas para la matriz B: ";
        std::cin >> filasB;
        std::cout << "Introduce el número de columnas para la matriz B: ";
        std::cin >> columnasB;
        matrizB = new MatrizSuma(filasB, columnasB);
        resultado = new MatrizSuma(filasA, columnasA);
    } else if (operacion == '2') {
        matrizA = new MatrizResta(filasA, columnasA);
        std::cout << "Introduce el número de filas para la matriz B: ";
        std::cin >> filasB;
        std::cout << "Introduce el número de columnas para la matriz B: ";
        std::cin >> columnasB;
        matrizB = new MatrizResta(filasB, columnasB);
        resultado = new MatrizResta(filasA, columnasA);
    } else if (operacion == '3') {
        matrizA = new MatrizMultiplicacion(filasA, columnasA);
        std::cout << "Introduce el número de filas para la matriz B: ";
        std::cin >> filasB;
        std::cout << "Introduce el número de columnas para la matriz B: ";
        std::cin >> columnasB;
        matrizB = new MatrizMultiplicacion(filasB, columnasB);
        resultado = new MatrizMultiplicacion(filasA, columnasB);
    } else if (operacion == '4') {
        matrizA = new MatrizHadmard(filasA, columnasA);
        std::cout << "Introduce el número de filas para la matriz B: ";
        std::cin >> filasB;
        std::cout << "Introduce el número de columnas para la matriz B: ";
        std::cin >> columnasB;
        matrizB = new MatrizHadmard(filasB, columnasB);
        resultado = new MatrizHadmard(filasA, columnasB);
    } else if (operacion == '5') {
        matrizA = new MatrizDeterminante(filasA, columnasA);
        resultado = new MatrizDeterminante(filasA, columnasA);
    } else if (operacion == '6') {
        matrizA = new Matriztranspue(filasA,columnasA);
        resultado = new Matriztranspue(columnasA, filasA);  
    } else if (operacion == '7'){
        matrizA = new MatrizInversaCofactores(filasA, columnasA);
        resultado = new MatrizInversaCofactores(filasA, columnasA);       
    } else {
        std::cerr << "Operación no válida." << std::endl;
        return 1;
    }

    std::cout << "Introduce los elementos de la matriz A:\n";
    matrizA->leerMatriz();

   //impongo condiciones para que tome o no valores para una matriz b
    if (operacion != '5' && operacion != '6' && operacion != '7') {
        std::cout << "Introduce los elementos de la matriz B:\n";
        matrizB->leerMatriz();
        matrizA->calcular(*matrizB, *resultado);
        std::cout << "El resultado de la operación es:\n";
        mostrarMatriz(*resultado);
    }else {
        matrizA->calcular(*matrizA, *resultado);
        mostrarMatriz(*resultado);
    }

//libero la memoria ocupada
    delete matrizA;
    if (matrizB) delete matrizB;
    if (resultado) delete resultado;

    return 0;
}
