#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Función para calcular el número de dígitos de un número
int contarDigitos(long long num) {
    return to_string(num).length();
}

// Función para extraer los dígitos centrales de un número
long long extraerDigitosCentrales(long long num, int digitos) {
    string numStr = to_string(num);
    int inicio = (numStr.length() - digitos) / 2;
    return stoll(numStr.substr(inicio, digitos));
}

void metodoProductoMedio(long long semilla1, long long semilla2, int digitos, int cantidad) {
    if (contarDigitos(semilla1) != digitos || contarDigitos(semilla2) != digitos) {
        cout << "Las semillas deben tener " << digitos << " dígitos." << endl;
        return;
    }
    cout << "Generando " << cantidad << " números aleatorios usando el método del producto medio:\n";
    std::ofstream datos("NumerosAleatorios2.dat");
    datos << "n" << "\t" << "semilla1" << "\t" << "semilla2" << "\t" << "producto" << "\t" << "siguiente" << "\n";
    for (int i = 0; i < cantidad; ++i) {
        long long producto = semilla1 * semilla2;
        long long siguiente = extraerDigitosCentrales(producto, digitos);

        cout << "Paso " << (i + 1) << ": " << semilla1 << " * " << semilla2 << " = " << producto << " -> " << siguiente << endl;
        datos << i + 1 << "\t" << semilla1 << "\t" << semilla2 << "\t" << producto << "\t" << siguiente << "\n";

        // Actualizar las semillas
        semilla1 = semilla2;
        semilla2 = siguiente;
    }
    datos.close();
}

int main() {
    long long semilla1, semilla2;
    int digitos, cantidad;

    cout << "Ingrese la primera semilla (n dígitos): ";
    cin >> semilla1;

    cout << "Ingrese la segunda semilla (n dígitos): ";
    cin >> semilla2;

    cout << "Ingrese el número de dígitos de las semillas: ";
    cin >> digitos;

    cout << "Ingrese la cantidad de números aleatorios a generar: ";
    cin >> cantidad;

    metodoProductoMedio(semilla1, semilla2, digitos, cantidad);
    
    std::ofstream plot("Graficador2.gp");
    plot << "set term png \n";
    plot << "set xlabel 'Paso' \n";
    plot << "set ylabel 'Producto medio' \n";
    plot << "set title 'Metodo del producto medio' \n";
    plot << "set output 'GráficasPMedio.png' \n";
    plot << "plot 'NumerosAleatorios2.dat' u 1:4 w p pt 8 lc rgb 'blue' t 'PM' ";
    plot.close();
    system("gnuplot Graficador2.gp");
    return 0;

}
