// José Daniel Rodríguez Cruz A01781933

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un sufijo con su índice original
struct Suffix {
    string suffix;
    int index;
};

// Función para comparar dos sufijos
bool compareSuffixes(Suffix a, Suffix b) {
    return a.suffix < b.suffix;
}

// Función para construir el arreglo de sufijos
vector<int> buildSuffixArray(string s) {
    int n = s.length();
    
    // Crear un vector de sufijos
    vector<Suffix> suffixes(n);

    // Inicializar el vector de sufijos
    for (int i = 0; i < n; i++) {
        suffixes[i].suffix = s.substr(i);
        suffixes[i].index = i;
    }

    // Ordenar los sufijos lexicográficamente
    sort(suffixes.begin(), suffixes.end(), compareSuffixes);

    // Construir el arreglo de sufijos
    vector<int> suffixArray(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }

    return suffixArray;
}

int main() {
    string s;
    cout << "Ingrese un string: ";
    cin >> s;

    // Agregar el caracter '$' al final del string
    s += '$';

    vector<int> suffixArray = buildSuffixArray(s);

    // Mostrar el arreglo de sufijos
    for (unsigned int i = 0; i < suffixArray.size(); i++) {
    cout << "Sufijo: " << s.substr(suffixArray[i]) << " - Posicion en T: " << suffixArray[i] + 1 << endl;
}

    return 0;
}