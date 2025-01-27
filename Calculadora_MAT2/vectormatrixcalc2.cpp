#include <iostream>
#include <vector>
#include <cmath>

// Clase Matriz
class Matriz {
public:
    int filas, columnas;
    std::vector<std::vector<double>> A;

    Matriz(int f, int c) : filas(f), columnas(c) {
        A.resize(filas, std::vector<double>(columnas, 0));
    }

    void leerMatriz(){
        for(int i = 0;i<filas; i++){
            std::vector<double> auxVect;
            for(int j = 0; j<columnas; j++){
                double AuxVal=0;
                std::cout<<"Ingrese el valor de la matriz en ["<<i<<"]["<<j<<"]";
                std::cin>>AuxVal;
                auxVect.push_back(AuxVal);
            }
            A.push_back(auxVect);

        }
    }
    

    void mostrarMatriz() const {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                std::cout << A[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Sobrecarga del operador +
    Matriz operator+(const Matriz& B) const {
        if (filas != B.filas || columnas != B.columnas) {
            std::cerr << "Error: Las matrices deben tener las mismas dimensiones para la suma.\n";
            exit(1);
        }
        Matriz resultado(filas, columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.A[i][j] = A[i][j] + B.A[i][j];
            }
        }
        return resultado;
    }

    // Sobrecarga del operador -
    Matriz operator-(const Matriz& B) const {
        if (filas != B.filas || columnas != B.columnas) {
            std::cerr << "Error: Las matrices deben tener las mismas dimensiones para la resta.\n";
            exit(1);
        }
        Matriz resultado(filas, columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.A[i][j] = A[i][j] - B.A[i][j];
            }
        }
        return resultado;
    }

    // Sobrecarga del operador *
    Matriz operator*(const Matriz& B) const {
        if (columnas != B.filas) {
            std::cerr << "Error: Las columnas de A deben ser iguales a las filas de B para multiplicar.\n";
            exit(1);
        }
        Matriz resultado(filas, B.columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < B.columnas; j++) {
                for (int k = 0; k < columnas; k++) {
                    resultado.A[i][j] += A[i][k] * B.A[k][j];
                }
            }
        }
        return resultado;
    }

    // Método para calcular el determinante (se asume que la matriz es cuadrada)
    double calcularDeterminante() const {
        if (filas != columnas) {
            std::cerr << "Error: El determinante solo se puede calcular para matrices cuadradas.\n";
            exit(1);
        }
        // Solo una implementación simple para matrices de 2x2
        if (filas == 2 && columnas == 2) {
            return A[0][0] * A[1][1] - A[0][1] * A[1][0];
        }
        std::cerr << "Error: Implementación solo para matrices 2x2.\n";
        return 0;
    }

    // Método para calcular la transpuesta
    Matriz transpuesta() const {
        Matriz resultado(columnas, filas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                resultado.A[j][i] = A[i][j];
            }
        }
        return resultado;
    }
};

// Función para realizar la operación según la entrada del usuario
void realizarOperacion(Matriz& A, Matriz& B, char operacion) {
    Matriz resultado(A.filas, A.columnas);

    switch (operacion) {
    case '1': // Suma
        resultado = A + B;
        std::cout << "El resultado de la suma es:\n";
        resultado.mostrarMatriz();
        break;
    case '2': // Resta
        resultado = A - B;
        std::cout << "El resultado de la resta es:\n";
        resultado.mostrarMatriz();
        break;
    case '3': // Multiplicación
        resultado = A * B;
        std::cout << "El resultado de la multiplicación es:\n";
        resultado.mostrarMatriz();
        break;
    case '4': // Determinante
        std::cout << "El determinante de A es: " << A.calcularDeterminante() << std::endl;
        break;
    case '5': // Transpuesta
        resultado = A.transpuesta();
        std::cout << "La transpuesta de A es:\n";
        resultado.mostrarMatriz();
        break;
    default:
        std::cerr << "Operación no válida." << std::endl;
        break;
    }
}

int main() {
    int filasA, columnasA, filasB, columnasB;
    char operacion;

    std::cout << "Introduce el número de filas para la matriz A: ";
    std::cin >> filasA;
    std::cout << "Introduce el número de columnas para la matriz A: ";
    std::cin >> columnasA;

    std::cout << "Introduce la operación: \n 1. Suma\n 2. Resta\n 3. Multiplicación\n 4. Determinante\n 5. Transpuesta\n";
    std::cin >> operacion;

    Matriz A(filasA, columnasA);
    std::cout << "Introduce los elementos de la matriz A:\n";
    A.leerMatriz();

    Matriz* B = nullptr;

    // Solo pedimos una segunda matriz para operaciones 1, 2 y 3
    if (operacion == '1' || operacion == '2' || operacion == '3') {
        std::cout << "Introduce el número de filas para la matriz B: ";
        std::cin >> filasB;
        std::cout << "Introduce el número de columnas para la matriz B: ";
        std::cin >> columnasB;

        B = new Matriz(filasB, columnasB);
        std::cout << "Introduce los elementos de la matriz B:\n";
        B->leerMatriz();
    }

    if (B) {
        realizarOperacion(A, *B, operacion);
        delete B;
    } else {
        realizarOperacion(A, A, operacion);
    }

    return 0;
}
