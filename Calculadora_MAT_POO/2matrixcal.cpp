#include <iostream>

const int MAX = 100;

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

    virtual void calcular(const Matriz& B, Matriz& resultado) = 0;  // Método virtual puro
    virtual ~Matriz() {}
};

class MatrizSuma : public Matriz {
public:
    MatrizSuma(int f, int c) : Matriz(f, c) {}

    void calcular(const Matriz& B, Matriz& resultado) override {
        if (filas != B.filas || columnas != B.columnas) {
            std::cerr << "Error: Las matrices deben tener las mismas dimensiones para sumarlas.\n";
            return;
        }
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.A[i][j] = A[i][j] + B.A[i][j];
            }
        }
    }
};

void mostrarMatriz(const Matriz& matriz) {
    for (int i = 0; i < matriz.filas; i++) {
        for (int j = 0; j < matriz.columnas; j++) {
            std::cout << matriz.A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int filasA, columnasA, filasB, columnasB;
    
    std::cout << "Introduce el número de filas para la matriz A: ";
    std::cin >> filasA;
    std::cout << "Introduce el número de columnas para la matriz A: ";
    std::cin >> columnasA;
    
    std::cout << "Introduce el número de filas para la matriz B: ";
    std::cin >> filasB;
    std::cout << "Introduce el número de columnas para la matriz B: ";
    std::cin >> columnasB;

    // Verificar que las dimensiones de las matrices A y B son iguales para poder sumarlas
    if (filasA != filasB || columnasA != columnasB) {
        std::cerr << "Error: Las matrices A y B deben tener las mismas dimensiones para sumarlas.\n";
        return 1;
    }

    MatrizSuma matrizA(filasA, columnasA);
    MatrizSuma matrizB(filasB, columnasB);
    MatrizSuma resultado(filasA, columnasA);

    std::cout << "Introduce los elementos de la matriz A:\n";
    matrizA.leerMatriz();
    
    std::cout << "Introduce los elementos de la matriz B:\n";
    matrizB.leerMatriz();
    
    matrizA.calcular(matrizB, resultado);

    std::cout << "La suma de las matrices es:\n";
    mostrarMatriz(resultado);

    return 0;
}
