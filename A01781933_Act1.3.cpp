// José Daniel Rodríguez Cruz A01781933

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Variables globales
int M, N;
vector<vector<int>> laberinto;
vector<vector<int>> solucionBacktracking;
vector<vector<int>> solucionBranchAndBound;

// Función para leer el archivo y cargar el laberinto en la memoria
void leeArchivo(string archivo) {
    ifstream input(archivo);
    input >> M >> N;
    // Reservamos memoria para el laberinto
    laberinto.resize(M, vector<int>(N));

    // Cargamos el laberinto en la memoria
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            input >> laberinto[i][j];
        }
    }

    // Cerramos el archivo
    input.close();
}

// Función para imprimir una matriz
void imprimeMatriz(const vector<vector<int>>& matriz) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para verificar si una casilla es válida en el laberinto
bool valida(int x, int y) {
    return (x >= 0 && x < M && y >= 0 && y < N && laberinto[x][y] == 1);
}

// Función de backtracking para resolver el laberinto
bool backtracking(int x, int y) {
    if (x == M - 1 && y == N - 1) {
        solucionBacktracking[x][y] = 1;
        return true; // Llegamos a la salida
    }

    if (valida(x, y)) {
        solucionBacktracking[x][y] = 1;

        // Movimiento hacia la derecha
        if (backtracking(x, y + 1)) {
            return true;
        }

        // Movimiento hacia abajo
        if (backtracking(x + 1, y)) {
            return true;
        }

        // Si ninguno de los movimientos es válido, retrocedemos
        solucionBacktracking[x][y] = 0;
        return false;
    }

    return false;
}

// Función de ramificación y poda para resolver el laberinto
bool branchAndBound(int x, int y) {
    if (x == M - 1 && y == N - 1) {
        solucionBranchAndBound[x][y] = 1;
        return true; // Llegamos a la salida
    }

    if (valida(x, y)) {
        solucionBranchAndBound[x][y] = 1;

        // Movimiento hacia la derecha
        if (branchAndBound(x, y + 1)) {
            return true;
        }

        // Movimiento hacia abajo
        if (branchAndBound(x + 1, y)) {
            return true;
        }

        // Si ninguno de los movimientos es válido, retrocedemos
        solucionBranchAndBound[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    string archivo = "laberinto.txt";
    leeArchivo(archivo);

    solucionBacktracking.resize(M, vector<int>(N, 0));
    solucionBranchAndBound.resize(M, vector<int>(N, 0));

    cout << "Solucion usando Backtracking:" << endl;
    backtracking(0, 0);
    imprimeMatriz(solucionBacktracking);

    cout << "\nSolucion usando Ramificacion y Poda:" << endl;
    branchAndBound(0, 0);
    imprimeMatriz(solucionBranchAndBound);

    return 0;
}

