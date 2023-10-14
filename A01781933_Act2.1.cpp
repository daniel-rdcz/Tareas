// José Daniel Rodríguez Cruz A01781933

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// Función para calcular el hash
long long calcularHash(std::string entrada) {
    int n = entrada.length();
    int p = 31;
    int m = 1e9 + 9;
    long long valorHash = 0;
    long long potencia = 1;
    
    for (int i = 0; i < n; i++) {
        valorHash = (valorHash + (entrada[i] - 'a' + 1) * potencia) % m;
        potencia = (potencia * p) % m;
    }
    
    return valorHash;
}

int main() {
    std::ifstream archivo("hash.txt");
    int n = 32; // Cambia este valor según tus necesidades

    std::vector<int> a(n, 0);
    char c;
    int col = 0;
    
    while (archivo.get(c)) {
        a[col] = (a[col] + static_cast<int>(c)) % 256;
        col = (col + 1) % n;
    }

    std::string resultado;
    
    for (int i = 0; i < n; i += 4) {
        int hashValue = (a[i] << 24) | (a[i + 1] << 16) | (a[i + 2] << 8) | a[i + 3];
        resultado += std::to_string(hashValue);
    }

    std::cout << "Resultado del hash: " << std::hex << std::uppercase << resultado << std::endl;

    archivo.close();

    return 0;
}

