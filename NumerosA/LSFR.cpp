#include <iostream>
#include <fstream>
#include <vector>

// Función LFSR para generar números pseudoaleatorios
std::vector<unsigned int> lfsr(unsigned int seed, unsigned int taps, int n) {
    std::vector<unsigned int> random_numbers;
    unsigned int state = seed; // Estado inicial (semilla)

    for (int i = 0; i < n; i++) {
        random_numbers.push_back(state); // Guardamos el estado actual
        unsigned int lsb = state & 1;   // Obtenemos el bit menos significativo
        state >>= 1;                    // Shift a la derecha
        if (lsb) {
            state ^= taps;              // Aplicamos el polinomio de realimentación
        }
    }
    return random_numbers;
}

// Guardar los números generados en un archivo .dat
void save_to_file(const std::string &filename, const std::vector<unsigned int> &data) {
    std::ofstream file(filename);
    file << "n" << "\t" << "LFSR" << "\n";
    if (file.is_open()) {
        for (size_t i = 0; i < data.size(); i++) {
            file << i + 1 << "\t" << data[i] << "\n"; // Índice y valor
        }
        file.close();
        std::cout << "Datos guardados en " << filename << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
    }
}

int main() {
    // Configuración del LFSR
    unsigned int seed = 0b1010111101101110;     // Semilla inicial (ejemplo: 1011 en binario)
    unsigned int taps = 0b1100000000001011;     // Polinomio de realimentación (ejemplo: 1001 en binario)
    int n = 1000;                    // Cantidad de números a generar

    // Generar números pseudoaleatorios
    std::vector<unsigned int> random_numbers = lfsr(seed, taps, n);

    // Guardar los resultados en un archivo .dat
    save_to_file("lfsr_output.dat", random_numbers);

    return 0;
}
