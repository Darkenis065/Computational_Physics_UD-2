#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Función para generar números pseudoaleatorios usando el método congruencial multiplicativo
void metodoCongruencialMultiplicativo(long long semilla, long long a, long long m, int cantidad) {
    if (semilla <= 0 || a <= 0 || m <= 0) {
        cout << "La semilla, el multiplicador y el módulo deben ser mayores que 0." << endl;
        return;
    }

    vector<long long> numeros(cantidad); // Vector para almacenar los números generados
    numeros[0] = semilla;               // Inicializar con la semilla

    cout << "Generando " << cantidad << " números aleatorios usando el método congruencial multiplicativo:\n";
    for (int i = 1; i < cantidad; ++i) {
        numeros[i] = (a * numeros[i - 1]) % m;
    }
    std::ofstream datos("RandomNCMP.dat");
    datos << "Paso" << "\t" << "X_n" <<"\n";
    for(int i = 1; i <1000; i++){
        datos << i << "\t" << numeros[i] << "\n";
    }
    datos.close();
    // Mostrar los números generados
    for (int i = 0; i < cantidad; ++i) {
        cout << "X_" << i << " = " << numeros[i] << endl;
    }
}

int main() {
    long long semilla, a, m;
    int cantidad;

    cout << "Ingrese la semilla (X0): ";
    cin >> semilla;

    cout << "Ingrese el multiplicador (a): ";
    cin >> a;

    cout << "Ingrese el módulo (m): ";
    cin >> m;

    cout << "Ingrese la cantidad de números a generar: ";
    cin >> cantidad;

    metodoCongruencialMultiplicativo(semilla, a, m, cantidad);

    std::ofstream plot("GraficadorCMP.gp");
    plot << "set term png \n";
    plot << "set xlabel 'Paso' \n";
    plot << "set ylabel 'Numero CMP' \n";
    plot << "set title 'Metodo congruencial multiplicativo'\n";
    plot << "set output 'GráficaCMP.png' \n";
    plot << "plot 'RandomNCMP.dat' u 1:2 w p pt 4 lc rgb 'red' t 'CMP'";
    plot.close();
    system("gnuplot GraficadorCMP.gp");

    return 0;
}
